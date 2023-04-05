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

// 1) Custom prompt function (helper to add color)
char* prompt_function(int state) {
    switch (state) {
        case 1:
            return GREEN "[GENERATE] >" RESET " ";
        case 2:
            return RED "[IMPLANT] >" RESET " ";
        default:
            return BLUE "[C2] >" RESET " ";
    }
}

// 2) Normalize string (helper to convert to lowercase)
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

// 3) Process command input
int process_command_input(char *input) {
    
    // Check null input
    if (strlen(input) > 0)
        add_history(input);

    // Parse results
    if (strcmp(input, "h") == 0 || strcmp(input, "help") == 0) {
        printf("Help\n");
        return 0;
    }
    else if (strcmp(input, "g") == 0 || strcmp(input, "generate") == 0) {
        printf("Generate\n");
        return 1;
    }
    else if (strcmp(input, "i") == 0 || strcmp(input, "implants") == 0) {
        printf("Implant\n");
        return 2;
    }
    else {
        printf("Default\n");
        return 0;
    }
}

// 4) Run Command Line Interface Loop
void run_cli(void) {
    char* input;
    int state = 0;
    
    while ((input = readline(prompt_function(state))) != NULL) {
        input = normalize_string(input);
        state = process_command_input(input);
        free(input);
    }
}

// 0) Main function
int main(void) {    
    run_cli();
    return 0;
}
