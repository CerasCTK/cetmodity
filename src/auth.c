#include "auth.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "account.h"
#include "io_util.h"

char *login(const dllist_deliver delivers) {
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
    const dllist_deliver delivers, char username[USERNAME_MAX_LEN],
    char password[PASSWORD_MAX_LEN]
) {
    if (strcmp(username, "admin") == 0 && strcmp(password, "123") == 0)
        return "-ADMIN-";

    deliver_node *found = dd_find_user(delivers, username, password);

    if (found == NULL)
        return "-NONE-";

    return found->deliver.id;
}

auth_state logout() {
    int opt;
    system("clear");
    printf("Do you want to exit or only logout?\n");
    printf("\t1. Logout\n");
    printf("\t2. Exit\n");
    printf("Input your option: ");
    scanf("%d", &opt);

    getchar();

    if (opt == 1)
        return logout_state;

    return exit_state;
}
