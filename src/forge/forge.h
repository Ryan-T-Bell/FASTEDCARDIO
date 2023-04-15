#ifndef FORGE_H
#define FORGE_H

struct Forge {
    const char* agent;
    const char* format;
    const char* target;
    const char* ip;
    const char* port;
};

void forge_agent(char* input);

#endif // FORGE_H
