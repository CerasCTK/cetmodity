#include "auth.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "account.h"
#include "io_util.h"

char *login(dllist_deliver delivers) {
    char username[USERNAME_MAX_LEN];
    char password[PASSWORD_MAX_LEN];

REINPUT:
    system("clear");
    printf("Username: ");
    input_string(username, USERNAME_MAX_LEN);
    printf("Password: ");
    input_without_showing_char(password, PASSWORD_MAX_LEN);

    char *id = get_account(delivers, username, password);

    if (strcmp(id, "-NONE-") == 0) {
        printf("Wrong user or password. Try again..\n");
        sleep(1);
        goto REINPUT;
    }

    return id;
}

char *get_account(
    dllist_deliver delivers, char user[USERNAME_MAX_LEN],
    char pass[PASSWORD_MAX_LEN]
) {
    if (strcmp(user, "admin") == 0 && strcmp(pass, "123") == 0)
        return "-ADMIN-";
    else {
        deliver_node *found = dd_find_user(delivers, user, pass);

        if (!found)
            return "-NONE-";
        else
            return found->deliver.id;
    }
}

logout_state logout() {
    int opt;
    system("clear");
    printf("Do you want to exit or only logout?\n");
    printf("\t1. Logout\n");
    printf("\t2. Exit\n");
    printf("Input your option: ");
    scanf("%d", &opt);
    char c = getchar();

    if (opt == LOGOUT_STATE)
        return LOGOUT_STATE;
    else
        return EXIT_STATE;
}
