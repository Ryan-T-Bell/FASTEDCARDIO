#include "colors.c"

// Parse command input when state = 0 [C2]
int parse_client(char *input) {
    if (strcmp(input, "h") == 0 || strcmp(input, "help") == 0) {
        printf("Help\n");
        return 0;
    }
    else if (strcmp(input, "f") == 0 || strcmp(input, "forge") == 0) {
        printf("Forge\n");
        return 1;
    }
    else if (strcmp(input, "e") == 0 || strcmp(input, "exit") == 0) {
        printf("Exit\n");
        return -1;
    }
    else {
        printf("Default\n");
        return 0;
    }
}
