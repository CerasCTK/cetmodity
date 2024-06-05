#include "item.h"

#include "io_util.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_same_item(const item i1, const item i2) {
    return strcmp(i1.product_name, i2.product_name) == 0;
}

item create_item(
    const char *product_name, const unsigned int quantity,
    const unsigned long unit_price
) {
    item new_item = { .quantity = quantity, .unit_price = unit_price };
    strcpy(new_item.product_name, product_name);

    return new_item;
}

item create_item_input() {
    char product_name[PRODUCT_MAX_NAME_LEN];
    unsigned int quantity;
    unsigned long unit_price;

    printf("\t- Input product's name: ");
    input_string(product_name, PRODUCT_MAX_NAME_LEN);
    printf("\t- Input quantity of the product: ");
    scanf("%u", &quantity);
    printf("\t- Input price of the product: ");
    scanf("%lu", &unit_price);
    getchar();

    return create_item(product_name, quantity, unit_price);
}

int get_item_info_len(const item item) {
    // Format of item info: `<product_name> - <quantity>\0`
    int product_name_len = strlen(item.product_name);
    int n_digits_quantity = floor(log10(item.quantity)) + 1;

    int n_spaces_char = 3; // [space]-[space]
    int n_end_char = 1;    // \0 char

    return product_name_len + n_digits_quantity + n_spaces_char + n_end_char;
}

char *get_item_info_string(item item) {
    const int info_len = get_item_info_len(item);
    char *array = malloc(info_len * sizeof(char));
    sprintf(array, "%s - %u", item.product_name, item.quantity);
    array[info_len - 1] = '\0';
    return array;
}
