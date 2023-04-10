#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ctype.h>
#include "cli_messages.h"
#include "cli.h"

// Custom prompt function (helper to add color)
char* prompt_function(int state) {
    switch (state) {
        case 0:
            return promptTasker;
        case 1:
            return promptForge;
        default:
            return promptUnknownState;
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
    for (int i = 0; i < len; i++)
        input[i] = tolower(input[i]);
    
    return input;
}

// Process command input
int process_command_input(int state, char *input) {
    
    // Check null input
    if (strlen(input) > 0)
        add_history(input);

    // Parse input
    if (state == 0)
        return parse_c2(input);
    else if (state == 1)
        return parse_forge(input);
    else
        return -1;
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
