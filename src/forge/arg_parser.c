#include <stdio.h>
#include <stdio.h>

// Return index of next instance of char c in input string
int next_index(int startIndex, char c, char* input) {
    int i = startIndex;
    while (i < strlen(input)) {
        if (input[i] == c)
            return i;
        i++;
    }
    return i;
}

// Return char* of next word in input string separated by ' ', '\0', or '\n'
char* next_word(int index, char* input) {
    int i = index;
    int len = strlen(input);
    char c;
    char* str = NULL;

    // Null check 1
    if (index == -1)
        return NULL;

    // Null check 2
    str = (char*) malloc(len + 1);
    if (str == NULL) {
        printf("Error: Failed to allocate memory.\n");
        return NULL;
    }

    int j = 0;

    // Build string
    while (i < len && input[i] != ' ' && input[i] != '\0' && input[i] != '\n') {
        str[j++] = input[i++];
    }

    // Null-terminate the new string
    str[j] = '\0';

    return str;
}
