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

char** sortArgument(char** arguments, char* flag, char* arg) {
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
    //else if (strcmp(flag, "") == 0)
        // Empty flag
    //else
        // Invalid flag
    
    return arguments;
}

// Parse forge command line and return normalized string for compile command
char** parseForgeInput(char* input) {
    int i = 5;
    char *flag, *arg;
    char** arguments[6];
    char** invalidFlags[6];
    
    while (i < strlen(input) && input[i] != '\0' && input[i] != '\n') {

        // Get next flag
        i = getNextIndexOf(i, '-', input);
        flag = getNextWord(i, input);

        // Get next argument
        i = getNextIndexOf(i, ' ', input) + 1;
        arg = getNextWord(i, input);

        arguments = sortArgument(arguments, flag, arg);
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