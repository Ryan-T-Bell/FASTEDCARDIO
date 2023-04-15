#ifndef FORGE_H
#define FORGE_H

struct Forge {
    char* agent;
    char* format;
    char* target;
    char* ip;
    char* port;
};

void forgeAgent(char* input);
void checkArguments(struct Forge* obj);
void parseArguments(struct Forge* obj);
void setDefaultsIfNull(struct Forge* obj);
void compile(struct Forge* obj);

#endif // FORGE_H
