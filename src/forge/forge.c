#include <string.h>
#include <stdlib.h>
#include "forge.h"
#include "arg_parser.c"
#include "compiler.c"

const char* msgInvalidFlag = "Invalid flag:\n"
                    "forge -a beacon -f exe -t windows -ip 192.168.86.100 -p 443\n"
                    "forge -a trigger -f library -t windows -arch x64\n"
                    "forge -a rat -f library -t linux -ip 192.168.86.100 -p 8080\n";

struct Forge* init() {
    struct Forge* obj = malloc(sizeof(struct Forge));
    obj->agent = "rat";
    obj->format = "exe";
    obj->target = "x86_64-w64-mingw32";
    obj->ip = "127.0.0.1";
    obj->port = "4444";
    return obj;
}

int validate_input_length(char* input) {
    if (strlen(input) < 8) {
        printf("Invalid input length.\n");
        return 0;
    } else {
        return 1;
    }
}

void set_argument(struct Forge* obj, char* flag, char* arg) {
    if (strcmp(flag, "-a") == 0)
        obj->agent = arg;
    else if (strcmp(flag, "-f") == 0)
        obj->format = arg;
    else if (strcmp(flag, "-target") == 0)
        obj->target = arg;
    else if (strcmp(flag, "-ip") == 0)
        obj->ip = arg;
    else if (strcmp(flag, "-p") == 0 || strcmp(flag, "-port") == 0)
        obj->port = arg;
    
}

void parse_arguments(struct Forge* obj, char* input) {
    int i = 5;
    char *flag, *arg;
    
    while (i < strlen(input) && input[i] != '\0' && input[i] != '\n') {

        // Get next flag
        i = next_index(i, '-', input);
        flag = next_word(i, input);

        // Get next argument
        i = next_index(i, ' ', input) + 1;
        arg = next_word(i, input);

        // Set argument
        set_argument(obj, flag, arg);
        
        // Free memory
        free(flag);
        free(arg);
    }
}

int is_agent(char* agent) {
    if(strcmp(agent, "beacon") == 0 || strcmp(agent, "trigger") == 0 || strcmp(agent, "rat") == 0)  {
        return 1;
    } else {
        printf("Invalid Flag | Agent (-a): %s\n  Acceptable values: beacon, trigger, or rat", agent);
        return 0;
    }
}

int is_format(char* format) {
    if(strcmp(format, "exe") == 0 || strcmp(format, "library") == 0)  {
        return 1;
    } else {
        printf("Invalid Flag | Format (-f): %s\n  Acceptable values: exe or library", format);
        return 0;
    }
}

int is_target(char* target) {
    if(strcmp(target, "windows") == 0 || strcmp(target, "linux") == 0)  {
        return 1;
    } else {
        printf("Invalid Flag | Target (-t): %s\n  Acceptable values: windows or linux", target);
        return 0;
    }
}

int is_ip(char* format, char* ip) {
    
    // Agent is trigger, no return IP needed
    if (strcmp(format, "trigger") == 0) {
        return 1;
    } else {
        char *token = strtok(ip, ".");
    
        while (token != NULL) {
            printf("Token: %s\n", token);
            token = strtok(NULL, ".");
    }
    }
}

int validate_arguments(struct Forge* obj) {
    
    
    return 1;
}

void compile(struct Forge* obj) {
    printf("Compile!\n");
}

void forge_agent(char* input) {
    if (validate_input_length(input)) {
        struct Forge* obj = init();
        
        parse_arguments(obj, input);

        if (validate_arguments(obj))
            compile(obj);
        
        free(obj);
    }
}