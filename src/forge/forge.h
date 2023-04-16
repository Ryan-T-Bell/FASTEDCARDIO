#ifndef FORGE_H
#define FORGE_H

struct Forge {
    char* agent;
    char* format;
    char* target;
    char* ip;
    int port;
};

void forge_agent(char* input);

#endif // FORGE_H
