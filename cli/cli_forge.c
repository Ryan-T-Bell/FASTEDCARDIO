// Parse results when state = 1 [FORGE]
int parse_forge(char *input) {
    if (strcmp(input, "h") == 0 || strcmp(input, "help") == 0) {
        printf("Help\n");
        return 0;
    }
    else if (strcmp(input, "c") == 0 || strcmp(input, "c2") == 0) {
        printf("C2\n");
        return 0;
    }
    else if (strcmp(input, "f") == 0 || strcmp(input, "forge") == 0) {
        printf("Generate\n");
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
