#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include "forge.h"

//////////////////////////////////////////////////////////////////////////////////////////
// Struct Functions
//////////////////////////////////////////////////////////////////////////////////////////
void init(struct Forge* obj) {
    if (obj == NULL)
        return;

    obj->agent = NULL;
    obj->format = NULL;
    obj->target = NULL;
    obj->ip = NULL;
    obj->port = 0;
}

void free_forge(struct Forge* obj) {
    if (obj->agent != NULL)
        free(obj->agent);
    if (obj->format != NULL)
        free(obj->format);
    if (obj->target != NULL)
        free(obj->target);
    if (obj->ip != NULL) 
        free(obj->ip);
}

//////////////////////////////////////////////////////////////////////////////////////////
// Getters and Setters
//////////////////////////////////////////////////////////////////////////////////////////

// Getters for each member of the struct
const char* get_agent(struct Forge* obj) {
    return obj->agent;
}

const char* get_format(struct Forge* obj) {
    return obj->format;
}

const char* get_target(struct Forge* obj) {
    return obj->target;
}

const char* get_ip(struct Forge* obj) {
    return obj->ip;
}

int get_port(struct Forge* obj) {
    return obj->port;
}

// Setters for each member of the struct
void set_agent(struct Forge* obj, const char* agent) {
    if (obj->agent != NULL)
        free(obj->agent);

    obj->agent = strdup(agent);
}

void set_format(struct Forge* obj, const char* format) {
    if (obj->format != NULL)
        free(obj->format);

    obj->format = strdup(format);
}

void set_target(struct Forge* obj, const char* target) {
    if (obj->target != NULL)
        free(obj->target);
    
    if (strcmp(target, "windows") == 0)
        obj->target = strdup("x86_64-w64-mingw32");
        
    else if (strcmp(target, "linux") == 0)
        obj->target = strdup("x86_64-pc-linux-gnu");
    else
        obj->target = strdup(target);
}

void set_ip(struct Forge* obj, const char* ip) {
    if (obj->ip != NULL)
        free(obj->ip);

    obj->ip = strdup(ip);
}

void set_port(struct Forge* obj, int port) {
    obj->port = port;
}

void set_argument(struct Forge* obj, char* flag, char* arg) {
    
    if (flag[0] == '\0' || arg[0] == '\0') {
        return;

    } else if (strcmp(flag, "-a") == 0 || strcmp(flag, "-agent") == 0) {
        set_agent(obj, arg);
    
    } else if (strcmp(flag, "-f") == 0 || strcmp(flag, "-format") == 0) {
        set_format(obj, arg);

    } else if (strcmp(flag, "-t") == 0 || strcmp(flag, "-target") == 0) {
        set_target(obj, arg);
    
    } else if (strcmp(flag, "-ip") == 0) {
        set_ip(obj, arg);

    } else if (strcmp(flag, "-p") == 0 || strcmp(flag, "-port") == 0) {
        set_port(obj, atoi(arg));
    }
}


//////////////////////////////////////////////////////////////////////////////////////////
// Validators
//////////////////////////////////////////////////////////////////////////////////////////
int validate_input_length(char* input) {
    if (strlen(input) < 8) {
        printf("Invalid input length.\n");
        return 0;
    } else {
        return 1;
    }
}

int is_agent(const char* agent) {
    if (agent != NULL && (strcmp(agent, "beacon") == 0 || strcmp(agent, "trigger") == 0 || strcmp(agent, "rat") == 0))  {
        return 1;
    }
    printf("Invalid Flag | Agent (-a): %s\n  Acceptable values: beacon, trigger, or rat\n", agent);
    return 0;
}

int is_format(const char* format) {
    if (format != NULL && (strcmp(format, "exe") == 0 || strcmp(format, "library") == 0))  {
        return 1;
    }
    printf("Invalid Flag | Format (-f): %s\n  Acceptable values: exe or library\n", format);
    return 0;
}

int is_target(const char* target) {
    if (target != NULL && (strcmp(target, "x86_64-w64-mingw32") == 0 || strcmp(target, "i686-w64-mingw32") == 0 || strcmp(target, "x86_64-pc-linux-gnu") == 0 || strcmp(target, "i686-pc-linux-gnu") == 0 || strcmp(target, "aarch64-linux-gnu") == 0 || strcmp(target, "arm-linux-gnueabi") == 0 || strcmp(target, "arm-linux-gnueabihf") == 0))  {
        return 1;
    }
    printf("Invalid Flag | Target (-t): %s\n  Acceptable values: windows or linux\n", target);
    return 0;
}

int is_ip(const char* agent, const char* ip) {
    
    // Agent is trigger, no return IP needed
    if (strcmp(agent, "trigger") == 0) {
        return 1;
    
    } else if (ip == NULL) {
        printf("Invalid Flag | IP Address (-ip): %s\n  Acceptable value format: 127.0.0.1\n", ip);
        return 0;
    
    // Agent is beacon or rat, check if IP
    } else {
        struct sockaddr_in sa4;
        struct sockaddr_in6 sa6;

        // Try to parse as IPv4 address
        if (inet_pton(AF_INET, ip, &(sa4.sin_addr)) == 1)
            return 1;

        // Try to parse as IPv6 address
        if (inet_pton(AF_INET6, ip, &(sa6.sin6_addr)) == 1)
            return 1;

        printf("Invalid Flag | IP Address (-ip): %s\n  Acceptable value format: 127.0.0.1\n", ip);
        return 0;
    }
}

int is_port(const char* agent, const int port) {

    if (strcmp(agent, "trigger") == 0 || (port >= 1 && port <= 65535))
        return 1;

    printf("Invalid Flag | Port (-p): %d\n  Acceptable values: 1-65535\n", port);
    return 0;
}

int validate_arguments(struct Forge* obj) {
    return is_agent(get_agent(obj)) && 
            is_format(get_format(obj)) && 
            is_target(get_target(obj)) && 
            is_ip(get_agent(obj), get_ip(obj)) && 
            is_port(get_agent(obj), get_port(obj));
}

//////////////////////////////////////////////////////////////////////////////////////////
// Parsing
//////////////////////////////////////////////////////////////////////////////////////////
void parse_arguments(struct Forge* obj, char* input) {
    char* token;
    char* saveptr;
    const char* delimiter = " ";
    
    // Tokenize the input string using space as the delimiter
    token = strtok_r(input, delimiter, &saveptr);
    
    // Loop through each token and check for flags
    while (token != NULL) {
        // Check if the token starts with a "-"
        if (token[0] == '-') {

            // Extract the flag and argument
            char* flag = token;
            char* arg = strtok_r(NULL, delimiter, &saveptr);
            
            if (arg != NULL) {
                set_argument(obj, flag, arg);
            } else {
                printf("(flag, arg) = (%s, NULL)\n", flag);
            }
        }
        
        // Get the next token
        token = strtok_r(NULL, delimiter, &saveptr);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////
// Compiling
//////////////////////////////////////////////////////////////////////////////////////////

const char* x86_64_w64_mingw32 = "x86_64-w64-mingw32";             // 64-bit Windows using MinGW-w64 toolchain
const char* i686_w64_mingw32 = "i686-w64-mingw32";                 // 32-bit Windows using MinGW-w64 toolchain

const char* x86_64_pc_linux_gnu = "x86_64-pc-linux-gnu";           // 64-bit x86 Linux
const char* i686_pc_linux_gnu = "i686-pc-linux-gnu";               // 32-bit x86 Linux

const char* aarch64_linux_gnu = "aarch64-linux-gnu";               // 64-bit ARM (AArch64) Linux
const char* arm_linux_gnueabi = "arm-linux-gnueabi";               // ARM Linux with EABI (Embedded ABI)
const char* arm_linux_gnueabihf = "arm-linux-gnueabihf";           // ARM Linux with hard-float ABI



void compile(struct Forge* obj) {
    // char * command = malloc(1000);
    // sprintf(command, "gcc -march= %s, -o %s %s.c -lssl -lcrypto\n", target, agent, agent);
    // system(command);
    // free(command);
}

//////////////////////////////////////////////////////////////////////////////////////////
// Testing
//////////////////////////////////////////////////////////////////////////////////////////
void print_forge(struct Forge* obj) {
    printf("Agent: %s\n", get_agent(obj));
    printf("Format: %s\n", get_format(obj));
    printf("Target: %s\n", get_target(obj));
    printf("IP: %s\n", get_ip(obj));
    printf("Port: %d\n", get_port(obj));
}


//////////////////////////////////////////////////////////////////////////////////////////
// Main function
//////////////////////////////////////////////////////////////////////////////////////////
void forge_agent(char* input) {
    if (validate_input_length(input)) {
        struct Forge obj;
        init(&obj);
        
        parse_arguments(&obj, input);
        print_forge(&obj);

        if (validate_arguments(&obj))
            compile(&obj);
        
        free_forge(&obj);
    }
}
