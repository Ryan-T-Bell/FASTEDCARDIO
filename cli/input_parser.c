#include "messages.h"

int parse_c2(char *input) {
    if (strcmp(input, "?") == 0 || strcmp(input, "h") == 0 || strcmp(input, "help") == 0) {
        printf("%s", msgForgeHelp);
        return 0;
    }
    else if (strcmp(input, "e") == 0 || strcmp(input, "exit") == 0) {
        printf("%s", msgExit);
        return -1;
    }
    else if (strcmp(input, "f") == 0 || strcmp(input, "forge") == 0) {
        printf("Forge\n");
        return 1;
    }

    else {
        printf("%s", msgInvalid);
        return 0;
    }
}


int parse_lp(char *input) {
    return 1;
}

int parse_agent(char *input) {
    return 2;
}