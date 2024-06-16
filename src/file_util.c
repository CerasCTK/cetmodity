#include "file_util.h"
#include "dllist_item.h"

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
