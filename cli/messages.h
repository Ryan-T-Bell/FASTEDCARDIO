#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"
#define RESET "\033[0m"

#ifndef MESSAGES_H
#define MESSAGES_H

// CLI Prompts
const char* promptTasker = BLUE "[TASKER] >" RESET " ";
const char* promptForge = GREEN "[FORGE] >" RESET " ";
const char* promptUnknownState = RED "[ERROR]" RESET " cli.c: Unknown state";

// Shared Messages
const char* msgExit = "Are you sure you want to exit? (y/n)\n";
const char* msgInvalid = YELLOW "[Invalid Input] " RESET "Enter \"help\" or \"h\" for input instructions. \n";

// Tasker Messages
const char* msgTaskerHelp = GREEN "HELP:\n" RESET;

// Forge Messages
const char* msgForgeHelp = GREEN "HELP:\n" RESET
                      "Available commands:\n"
                      "?/h help (this menu): Display this menu\n"
                      "e exit: Exit the program\n"
                      "f forge: Forge an agent (a) or listening post (lp).\n"
                      ;

#endif // MESSAGES_H