#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ctype.h>

#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

// Custom prompt function (helper to add color)
char* prompt_function(int state) {
    switch (state) {
        case 1:
            return GREEN "[FORGE] >" RESET " ";
        default:
            return BLUE "[C2] >" RESET " ";
    }
}

// Normalize string (helper to convert to lowercase)
char* normalize_string(char* input) {
    int len = strlen(input);
    
    // Remove newline character, if any
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }
    
    // Convert string to lowercase
    for (int i = 0; i < len; i++) {
        input[i] = tolower(input[i]);
    }
    
    return input;
}

// Parse command input when state = 0 [C2]
int parse_c2(char *input) {
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

// Process command input
int process_command_input(int state, char *input) {
    
    // Check null input
    if (strlen(input) > 0)
        add_history(input);

    // Parse input
    if (state == 0)
        return parse_c2(input);
    else
        return parse_forge(input);
}

// Run command line interface loop
void run_cli(void) {
    char* input;
    int state = 0;
    
    while (state >= 0 && (input = readline(prompt_function(state))) != NULL) {
        input = normalize_string(input);
        state = process_command_input(state, input);
        free(input);
    }
}
