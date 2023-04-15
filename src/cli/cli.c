#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ctype.h>
#include "messages.h"
#include "input_parser.c"

// Custom prompt function
const char* promptFunction(int state) {
    switch (state) {
        case 0:
            return promptC2;
        case 1:
            return promptLP;
        case 2:
            return promptAgent;
        default:
            return promptUnknownState;
    }
}

// Normalize string (helper to convert to lowercase)
char* normalizeString(char* input) {
    int len = strlen(input);
    
    // Remove newline character
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
int processCommandInput(int state, char *input) {
    
    // Check null input
    if (strlen(input) > 0)
        add_history(input);

    // Parse input
    switch (state) {
        case 0:
            return parseC2(input);
        case 1:
            return parseLP(input);
        case 2:
            return parseAgent(input);
        default:
            return -1;
    }
}

// Run command line interface loop
int runCli(void) {
    char* input;
    int state = 0;
    
    while (state >= 0 && (input = readline(promptFunction(state))) != NULL) {
        input = normalizeString(input);
        state = processCommandInput(state, input);
        free(input);
    }

    return 0;
}
