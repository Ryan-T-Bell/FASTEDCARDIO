#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ctype.h>
#include "cli.h"
#include "messages.h"
#include "input_parser.c"

// Custom prompt function
const char* prompt_function(int state) {
    switch (state) {
        case 0:
            return BLUE "[C2] >" RESET " ";
        case 1:
            return GREEN "[LP] >" RESET " ";
        case 2:
            return RED "[AGENT] >" RESET " ";
        default:
            return RED "[ERROR]" RESET " cli.c: Unknown state";
    }
}

// Normalize string (helper to convert to lowercase)
void normalize_string(char* input) {
    int i = 0, j = 0, len = strlen(input);
    
    // Remove newline character
    if (len > 0 && input[len-1] == '\n') {
        input[len-1] = '\0';
        len--;
    }
    
    // Skip leading whitespace
    for (; i < len && isspace(input[i]); i++);
    
    // Convert string to lowercase
    for (; i < len; i++) {
        input[j] = tolower(input[i]);
        j++;
    }

    // Null terminate string
    for (; j < len; j++)
        input[j] = '\0';
}

// Process command input
int process_command_input(int state, char *input) {
    
    // Check null input
    if (strlen(input) > 0)
        add_history(input);

    // Parse input
    switch (state) {
        case 0:
            return parse_C2(input);
        case 1:
            return parse_lp(input);
        case 2:
            return parse_agent(input);
        default:
            return -1;
    }
}

// Run command line interface loop
int run_cli(void) {
    char* input;
    int state = 0;
    
    while (state >= 0 && (input = readline(prompt_function(state))) != NULL) {
        normalize_string(input);
        state = process_command_input(state, input);
        free(input);
    }

    return 0;
}
