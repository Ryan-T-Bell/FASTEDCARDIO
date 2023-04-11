#include "messages.h"
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

int isForge(char* input) {
    return input[0] == 'f' && input[1] == 'o' && input[2] == 'r' && input[3] == 'g' && input[4] == 'e';
}

int getNextIndexOf(int index, char c, char* input) {
    int i = index;
    while (i < strlen(input)) {
        if (input[i] == c)
            return i;
        i++;
    }
    return i;
}

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
    char** arguments = (char**)malloc(6 * sizeof(char*));

    while (i < strlen(input) && input[i]) {
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

    free(flag);
    free(arg);

    printf("forge -a %s -f %s -os %s -arch %s -ip %s -p %s\n", arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5]);
    return arguments;
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
        parseForgeInput(input);             // TODO Implement
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