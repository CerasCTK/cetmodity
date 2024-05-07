#include "io_util.h"

#include <asm-generic/ioctls.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

void input_without_showing_char(char *dest, unsigned short size) {
    static struct termios old, new;

    // Saving old settings of STDIN_FILENO and copy settings for hide char
    tcgetattr(STDIN_FILENO, &old);
    new = old;

    // Setting the approriate bit in the termios struct
    new.c_lflag &= ~(ECHO);

    // Set new bits
    tcsetattr(STDIN_FILENO, TCSANOW, &new);

    // Reading char to destination
    input_string(dest, size);

    // Reset STDIN_FILENO
    tcsetattr(STDIN_FILENO, TCSANOW, &old);

    printf("\n");
}

void input_string(char *dest, unsigned short size) {
    int counter = 0;
    char c;
    while ((c = getchar()) != '\n' && c != EOF && counter < size) {
        dest[counter++] = c;
    }

    dest[counter] = '\0';
}

void print_center(char **text, unsigned short lines) {
    // Get columns and lines in output
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);

    int rows = w.ws_row;
    int cols = w.ws_col;

    system("clear");

    int y = (rows - lines) / 2;
    for (int i = 0; i < y; i++)
        printf("\n");

    for (int i = 0; i < lines; i++) {
        char *current_txt = text[i];
        int text_len = strlen(current_txt);
        int f_width = text_len + (cols - text_len) / 2;
        printf("%*s\n", f_width, text[i]);
    }

    for (int i = 0; i < y; i++)
        printf("\n");
}
