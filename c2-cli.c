#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int argc, char *argv[]) {
    char* input;
    
    while ((input = readline("> ")) != NULL) {
        if (strlen(input) > 0) {
            add_history(input);
        }
        
        printf("You entered: %s\n", input);
        
        free(input);
    }
    
    return 0;
}
