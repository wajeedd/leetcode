#include <stdlib.h>

char* defangIPaddr(char* address) {
    int i = 0, j = 0;
    char *result = (char*)malloc(4 * 16 + 1);  
    while(address[i] != '\0') {
        if(address[i] == '.') {
            result[j++] = '[';
            result[j++] = '.';
            result[j++] = ']';
        } else {
            result[j++] = address[i];
        }
        i++;
    }

    result[j] = '\0';
    return result;
}