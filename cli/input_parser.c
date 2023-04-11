#include "messages.h"
#include <string.h>

////////////////////////////////////////////////////////////////////////
// Shared
////////////////////////////////////////////////////////////////////////

int isHelp(char* input) {
    return strcmp(input, "?") == 0 || strcmp(input, "h") == 0 || strcmp(input, "help") == 0;
}

int isExit(char* input) {
    return strcmp(input, "e") == 0 || strcmp(input, "exit") == 0;
}

int confirmIfUserWantsToExit(void) {
    char* exitInput;
    exitInput = readline(msgExit);
    
    if (strcmp(exitInput, "y") == 0 || strcmp(exitInput, "yes") == 0)
        return -1;
    return 0;
}

int isLS(char* input) {
    return strcmp(input, "ls") == 0 || strcmp(input, "dir") == 0;
}

int isRM(char* input) {
    return strcmp(input, "rm") == 0;
}

int isUse(char* input) {
    return strcmp(input, "use") == 0 || strcmp(input, "u") == 0;
}

////////////////////////////////////////////////////////////////////////
// C2 Functions
////////////////////////////////////////////////////////////////////////

char* getFirstWord(char* input) {
    char firstWord[20];
    int i = 0;

    // Extract the first word from the input string
    while (input[i] != '\0' && input[i] != ' ' && i < 20) {
        firstWord[i] = input[i];
        i++;
    }
    
    // Null-terminate the first word string
    firstWord[i] = '\0';
    return firstWord;
}

int isForge(char* input) {
    if (strcmp(getFirstWord(input), "forge") == 0)
        return 1;
    
    return 0;
}

// Normalize and parse forge command
int parseForgeInput(char* input) {
    char *token;
    
    // First call to strtok with input string
    token = strtok(input, " ");


    while (token != NULL) {
        printf("%s\n", token); // Print each token
        token = strtok(NULL, " "); // Subsequent calls to strtok with NULL as first argument
    }
    return 1;
}

// Parse input if in C2 state
int parse_c2(char *input) {
    if (isHelp(input)) {
        printf("%s", msgForgeHelp);
    }
    else if (isExit(input)) {
        return confirmIfUserWantsToExit();
    }
    else if (isLS(input)) {
        printf("LS\n");                     // TODO Implement
    }
    else if (isRM(input)) {
        printf("rm\n");                     // TODO Implement
    }
    else if (isForge(input)) {
        printf("Forge\n");                  // TODO Implement
    }
    else if (isUse(input)) {
        printf("Use\n");                    // TODO Implement
    }
    else {
        printf("%s", msgInvalid);
    }
    return 0;
}

////////////////////////////////////////////////////////////////////////
// LP Functions
////////////////////////////////////////////////////////////////////////


int parse_lp(char *input) {
    return 1;
}

////////////////////////////////////////////////////////////////////////
// Agent Functions
////////////////////////////////////////////////////////////////////////

int parse_agent(char *input) {
    return 2;
}