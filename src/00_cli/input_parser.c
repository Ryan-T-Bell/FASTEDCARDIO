#include "colors.h"
#include "forge/forge.h"
#include <string.h>


//////////////////////////////////////////////////////////////////////////////////////////
// Help
//////////////////////////////////////////////////////////////////////////////////////////
int is_help(char* input) {
    return strcmp(input, "?") == 0 || strcmp(input, "h") == 0 || strcmp(input, "help") == 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Exit
//////////////////////////////////////////////////////////////////////////////////////////
int is_exit(char* input) {
    return strcmp(input, "e") == 0 || strcmp(input, "exit") == 0;
}

int confirm_exit(void) {
    char* exitInput;
    exitInput = readline("Are you sure you want to exit? (y/n)\n");
    
    if (strcmp(exitInput, "y") == 0 || strcmp(exitInput, "yes") == 0)
        return -1;
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Forge
//////////////////////////////////////////////////////////////////////////////////////////
int is_forge(char* input) {
    if (strlen(input) < 5)
        return 0;
    return input[0] == 'f' && input[1] == 'o' && input[2] == 'r' && input[3] == 'g' && input[4] == 'e';
}

//////////////////////////////////////////////////////////////////////////////////////////
// LS
//////////////////////////////////////////////////////////////////////////////////////////
int is_ls(char* input) {
    return strcmp(input, "ls") == 0 || strcmp(input, "dir") == 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Remove
//////////////////////////////////////////////////////////////////////////////////////////
int is_rm(char* input) {
    return strcmp(input, "rm") == 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// Use
//////////////////////////////////////////////////////////////////////////////////////////
int is_use(char* input) {
    return strcmp(input, "use") == 0 || strcmp(input, "u") == 0;
}

//////////////////////////////////////////////////////////////////////////////////////////
// C2
//////////////////////////////////////////////////////////////////////////////////////////
int parse_C2(char *input) {
    
    if (is_exit(input))                         // Exit
        return confirm_exit();
    
    else if (is_forge(input))                  // Forge
        forge_agent(input);

    else if (is_help(input))                    // Help
        printf("%s", GREEN "HELP:\n" RESET
                      "Available commands:\n"
                      "?/h help (this menu): Display this menu\n"
                      "e exit: Exit the program\n"
                      "f forge: Forge an agent (a) or listening post (lp).\n"
                      );
    
    else if (is_ls(input))                      // LS
        printf("LS\n");                        // TODO Implement
    
    else if (is_rm(input))                      // RM
        printf("rm\n");                        // TODO Implement
    
    else if (is_use(input))                     // Use
        printf("Use\n");                       // TODO Implement
    
    else
        printf("%s", YELLOW "Invalid Input " RESET "Enter \"help\" or \"h\" for input instructions. \n");
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