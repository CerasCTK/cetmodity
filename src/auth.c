#include "auth.h"

#include "account.h"
#include "cetmodity_menu.h"
#include "io_util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
    const dllist_deliver delivers, char username[USERNAME_MAX_LEN + 1],
    char password[PASSWORD_MAX_LEN + 1]
) {
    if (strcmp(username, "admin") == 0 && strcmp(password, "123") == 0)
        return "-ADMIN-";

    deliver_node *found = dd_find_user(delivers, username, password);

    if (found == NULL)
        return "-NONE-";

    return found->deliver.id;
}

logout_state logout() {
    int opt;
    logout_menu();
    printf("Input your option: ");
    scanf("%d", &opt);

    getchar();

    if (opt == 1)
        return cetmodity_logout;

    return cetmodity_exit;
}
