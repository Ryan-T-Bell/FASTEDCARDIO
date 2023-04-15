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
const char* promptC2 = BLUE "[C2] >" RESET " ";
const char* promptLP = GREEN "[LP] >" RESET " ";
const char* promptAgent = RED "[AGENT] >" RESET " ";
const char* promptUnknownState = RED "[ERROR]" RESET " cli.c: Unknown state";

// Shared Messages
const char* msgExit = "Are you sure you want to exit? (y/n)\n";
const char* msgInvalid = YELLOW "Invalid Input " RESET "Enter \"help\" or \"h\" for input instructions. \n";

// C2 Messages
const char* msgForgeHelp = GREEN "HELP:\n" RESET
                      "Available commands:\n"
                      "?/h help (this menu): Display this menu\n"
                      "e exit: Exit the program\n"
                      "f forge: Forge an agent (a) or listening post (lp).\n";

const char* msgInvalidFlag = "Invalid flag:\n"
                    "forge -a beacon -f exe -os windows -arch x86 -ip 192.168.86.100 -p 443\n"
                    "forge -a trigger -f library -os windows -arch x64\n"
                    "forge -a rat -f library -os linux -arch x64 -ip 192.168.86.100 -p 8080\n";

// LP Messages


// Agent Messages


#endif // MESSAGES_H