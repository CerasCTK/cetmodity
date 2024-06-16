#include "file_util.h"

#include "account.h"
#include "deliver.h"
#include "dllist_item.h"
#include "dllist_order.h"
#include "uuid_util.h"

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

bool is_file_exist(const char *const file_name) {
    return access(file_name, F_OK) == 0;
}

void write_delivers_to_file(
    const char *const file_name, const dllist_deliver *const list
) {
    const int list_size = dd_size(list);
    FILE *const file = fopen(file_name, "w");

    if (file == NULL) {
        return;
    }

    fprintf(file, "%d\n", list_size);
    for (deliver_node *runner = list->head; runner != NULL;
         runner = runner->next) {
        write_deliver_to_file(file, runner->deliver);
    }

    fclose(file);
}

void write_deliver_to_file(FILE *const file, const deliver *const deliver) {
    fprintf(file, "%s\n", deliver->id);
    fprintf(file, "%s\n", deliver->name);
    fprintf(file, "%s\n", deliver->phone_number);
    write_account_to_file(file, deliver->account);
}

void write_account_to_file(FILE *const file, const account account) {
    fprintf(file, "%s\n", account.username);
    fprintf(file, "%s\n", account.password);
}

void write_orders_to_file(
    const char *const file_name, const dllist_order *const list
) {
    const int list_size = do_size(list);
    FILE *const file = fopen(file_name, "w");

    if (file == NULL) {
        return;
    }

    fprintf(file, "%d\n", list_size);
    for (order_node *runner = list->head; runner != NULL;
         runner = runner->next) {
        write_order_to_file(file, runner->order);
    }

    fclose(file);
}

void write_order_to_file(FILE *const file, const order *const order) {
    fprintf(file, "%s\n", order->id);

    write_sender_to_file(file, order->sender);
    write_receiver_to_file(file, order->receiver);

    fprintf(file, "%s\n", order->created_at);

    write_items_to_file(file, order->item_list);
}

void write_sender_to_file(FILE *const file, const sender sender) {
    fprintf(file, "%s\n", sender.name);
    fprintf(file, "%s\n", sender.phone_number);
    write_coordinate_to_file(file, sender.location);
}

void write_receiver_to_file(FILE *const file, const receiver receiver) {
    fprintf(file, "%s\n", receiver.name);
    fprintf(file, "%s\n", receiver.phone_number);
    write_coordinate_to_file(file, receiver.location);
}

void write_coordinate_to_file(FILE *const file, const coordinate coordinate) {
    fprintf(file, "%f\n", coordinate.latitude);
    fprintf(file, "%f\n", coordinate.longitude);
}

void write_items_to_file(FILE *const file, const dllist_item *const list) {
    const int list_size = di_size(list);

    fprintf(file, "%d\n", list_size);

    for (item_node *runner = list->head; runner != NULL;
         runner = runner->next) {
        write_item_to_file(file, runner->item);
    }
}

void write_item_to_file(FILE *const file, const item *const item) {
    fprintf(file, "%s\n", item->product_name);
    fprintf(file, "%d\n", item->quantity);
    fprintf(file, "%lu\n", item->unit_price);
}

void write_linker_to_file(
    const char *const file_name, const dllist_order *const list
) {
    FILE *const file = fopen(file_name, "w");

    if (file == NULL) {
        return;
    }

    int counter = 0;

    for (order_node *runner = list->head; runner != NULL;
         runner = runner->next) {
        if (strlen(runner->order->deliver_id) != 0) {
            counter++;
            fprintf(file, "%s\n", runner->order->id);
            fprintf(file, "%s\n", runner->order->deliver_id);
            fprintf(file, "%d\n", runner->order->status);
            fprintf(file, "%s\n", runner->order->delivered_at);
        }
    }

    fclose(file);

    append_number_to_first_line(file_name, counter);
}

void append_number_to_first_line(
    const char *const file_name, const int number
) {
    // Read file
    FILE *file = fopen(file_name, "r");

    if (file == NULL) {
        return;
    }

    // Determine the size of the file
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Keep current content file into buffer
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Memory allocation error");
        fclose(file);
        return;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';

    fclose(file);

    // Reopen file to write
    file = fopen(file_name, "w");
    if (file == NULL) {
        free(buffer);
        return;
    }

    fprintf(file, "%d\n", number);
    fwrite(buffer, 1, file_size, file);

    fclose(file);
    free(buffer);
}

void read_delivers_from_file(
    const char *const file_name, dllist_deliver *const list
) {
    int num_of_delivers;

    FILE *const file = fopen(file_name, "r");
    if (file == NULL)
        return;

    char buffer[128];
    fgets(buffer, sizeof(buffer), file);
    num_of_delivers = atoi(buffer);

    for (int i = 0; i < num_of_delivers; i++) {
        deliver *deliver = read_deliver_from_file(file);
        dd_insert(list, deliver);
    }

    fclose(file);
}

deliver *read_deliver_from_file(FILE *const file) {
    deliver *deliver = malloc(sizeof(struct deliver));

    char buffer[256];

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(deliver->id, buffer);

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(deliver->name, buffer);

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(deliver->phone_number, buffer);

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(deliver->account.username, buffer);

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(deliver->account.password, buffer);

    do_init(&deliver->orders);

    return deliver;
}

void read_orders_from_file(
    const char *const file_name, dllist_order *const list
) {
    int num_of_orders;

    FILE *const file = fopen(file_name, "r");
    if (file == NULL)
        return;

    char buffer[128];
    fgets(buffer, sizeof(buffer), file);
    num_of_orders = atoi(buffer);

    for (int i = 0; i < num_of_orders; i++) {
        order *order = read_order_from_file(file);
        do_insert(list, order);
    }

    fclose(file);
}

order *read_order_from_file(FILE *const file) {
    order *order = malloc(sizeof(struct order));

    char buffer[256];

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(order->id, buffer);

    // Sender
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(order->sender.name, buffer);

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(order->sender.phone_number, buffer);

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    float sender_latitude = strtof(buffer, NULL);
    order->sender.location.latitude = sender_latitude;

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    float sender_longitude = strtof(buffer, NULL);
    order->sender.location.longitude = sender_longitude;

    // Receiver
    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(order->receiver.name, buffer);

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(order->receiver.phone_number, buffer);

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    float receiver_latitude = strtof(buffer, NULL);
    order->receiver.location.latitude = receiver_latitude;

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    float receiver_longitude = strtof(buffer, NULL);
    order->receiver.location.longitude = receiver_longitude;

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(order->created_at, buffer);

    di_init(&order->item_list);

    read_items_from_file(file, order->item_list);

    return order;
}

void read_items_from_file(FILE *const file, dllist_item *const list) {
    int num_of_items;

    char buffer[128];
    fgets(buffer, sizeof(buffer), file);
    num_of_items = atoi(buffer);

    for (int i = 0; i < num_of_items; i++) {
        item *item = read_item_from_file(file);
        di_insert(list, item);
    }
}

item *read_item_from_file(FILE *const file) {
    item *item = malloc(sizeof(struct item));

    char buffer[256];

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    strcpy(item->product_name, buffer);

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    unsigned int quantity = strtoul(buffer, NULL, 10);
    item->quantity = quantity;

    fgets(buffer, sizeof(buffer), file);
    buffer[strcspn(buffer, "\n")] = '\0';
    unsigned int unit_price = strtoul(buffer, NULL, 10);
    item->unit_price = unit_price;

    return item;
}

void link_order_to_deliver_from_file(
    const char *const file_name, dllist_order *const orders,
    dllist_deliver *const delivers
) {
    int num_of_links;

    FILE *const file = fopen(file_name, "r");
    if (file == NULL) {
        return;
    }

    char buffer[128];
    fgets(buffer, sizeof(buffer), file);
    num_of_links = atoi(buffer);

    for (int i = 0; i < num_of_links; i++) {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = '\0';
        order_node *order_node = do_search_by_id(orders, buffer);
        if (order_node->order->status == 1 || order_node->order->status == 2) {
            printf("Order has been delivered!\n");
            continue;
        }

        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\n")] = '\0';
        deliver_node *deliver_node = dd_search_node_by_id(delivers, buffer);

        order_node->order->status = in_transit;
        strcpy(order_node->order->deliver_id, deliver_node->deliver->id);
        do_insert(deliver_node->deliver->orders, order_node->order);
    }
}
