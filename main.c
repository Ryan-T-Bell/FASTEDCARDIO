#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

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
char* prompt_function(void) {
    return BLUE "[C2] >" RESET " ";
}

// 2) Process command input
int process_command_input(char *input) {
    
    // Check null input
    if (strlen(input) > 0)
        add_history(input);

    // Switch
    input[strcspn(input, "\n")] = 0;

    // Use switch statement with strings
    switch (input[0]) {
        case 'h':
            printf("You entered Blue\n");
            break;
        case 'g':
            printf("You entered Green\n");
            break;
        case 'i':
            printf("You entered Red\n");
            break;
        default:
            printf("Invalid color entered\n");
            break;
    }

    return 0;
}

// 3) Run Command Line Interface Loop
void run_cli(void) {
    char* input;
    
    while ((input = readline(prompt_function())) != NULL) {
        process_command_input(input);
        free(input);
    }
}

// Main function
int main(void) {    
    run_cli();
    return 0;
}