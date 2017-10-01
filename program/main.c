#include <stdlib.h>
#include <string.h>
#include "client.h"
#include <stdio.h>

int main(int argc, char **argv) {
    int err_c;
    err_c = client_init();
    if (err_c == NETLINK_INIT_ERROR) {
        printf("Netlink initialisation error");
        return NETLINK_INIT_ERROR;
    }

    if (strcmp("get", argv[1]) == 0 && argc == 3) {
        char *key;
        char *value;
        size_t value_size;
        key = argv[2];
        if (client_get(key, &value, &value_size)) {
            printf("%s\n", value);
        } else {
            printf("Not found\n");
        }
        return 0;
    } else if (strcmp("set", argv[1]) == 0 && argc == 4) {
        char *key;
        char *value;
        key = argv[2];
        value = argv[3];
        client_set(key, value);
        return 0;
    } else {
        printf("usage: <set|get> <key> [value]\n");
        return -1;
    }
}
