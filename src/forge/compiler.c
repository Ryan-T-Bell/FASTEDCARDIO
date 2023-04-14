int argumentsValid(char ** arguments) {
    
    
    return 1;
}

char* getRandomName() {
    
}

int compile(char ** arguments) {
    char * agent = arguments[0];
    char * format = arguments[1];
    char * target = arguments[2];
    char * ip = arguments[3];
    char * port = arguments[4];
    
    char * command = malloc(1000);
    sprintf(command, "gcc -march= %s, -o %s %s.c -lssl -lcrypto\n", target, agent, agent);
    system(command);
    free(command);
    
    return 1;
}