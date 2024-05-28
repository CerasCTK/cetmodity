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
    while ((c = getchar()) != '\n' && c != EOF && counter < dest_size) {
        dest[counter++] = c;
    }

    dest[counter] = '\0';
}

void print_center(
    const unsigned short msg_len, const unsigned short lines,
    char messages[lines][msg_len]
) {
    // Get columns and lines in output
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    const int rows = w.ws_row;
    const int cols = w.ws_col;

    system("clear");

    const int y = (rows - lines) / 2;
    for (int i = 0; i < y; i++)
        printf("\n");

    for (int i = 0; i < lines; i++) {
        int f_width = msg_len + (cols - msg_len) / 2;
        printf("%*s\n", f_width, messages[i]);
    }

    for (int i = 0; i < y; i++)
        printf("\n");
}
