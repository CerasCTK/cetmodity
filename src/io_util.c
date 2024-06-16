#include "io_util.h"

#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

void input_without_showing_char(char *dest, const unsigned short dest_size) {
    static struct termios old, new;

    // Saving old settings of STDIN_FILENO and copy settings for hide char
    tcgetattr(STDIN_FILENO, &old);
    new = old;

    // Setting the approriate bit in the termios struct
    new.c_lflag &= ~(ECHO);

    // Set new bits
    tcsetattr(STDIN_FILENO, TCSANOW, &new);

    // Reading char to destination
    input_string(dest, dest_size);

    // Reset STDIN_FILENO
    tcsetattr(STDIN_FILENO, TCSANOW, &old);

    printf("\n");
}

void input_string(char *dest, const unsigned short dest_size) {
    int counter = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF && counter < dest_size - 1) {
        dest[counter++] = c;
    }

    dest[counter] = '\0';
}

void print_message_bottom_left(const char *message) {
    // Save the cursor position
    printf("\033[s");

    // Get lines in terminal display window
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    const int cols = w.ws_col;

    // Move the cursor to the bottom left
    printf("\033[%d;%dH", cols, 0);

    // Clear the line
    printf("\033[K");

    // Print the message
    printf("%s", message);

    // Restore the cursor position
    printf("\033[u");

    // Flush the output to ensure it appears immediately
    fflush(stdout);
}

void wait_for_enter() {
    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != '\n')
        // Ignore all input except Enter
        ;
}
