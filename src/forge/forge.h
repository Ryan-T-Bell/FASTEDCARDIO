#ifndef FORGE_H
#define FORGE_H

struct Forge {
    const char* agent;
    const char* format;
    const char* target;
    const char* ip;
    const char* port;
};

// main method for forge directory
void forge_agent(char* input);

// helpers 
struct Forge* init();
int validate_input(char* input);
void parse_arguments(struct Forge* obj, char* input);
void set_argument(struct Forge* obj, char* flag, char* arg);
int validate_arguments(struct Forge* obj);
void compile(struct Forge* obj);

#endif // FORGE_H
