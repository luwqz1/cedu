#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *maskify(char *string) {
    char *maskify = (char *)malloc((strlen(string) + 1) * sizeof(char));
    for (int i = 0; i < strlen(string); i++) {
        if (i < strlen(string) - 4)
            maskify[i] = string[i];
        else
            maskify[i] = '#';
    }
    maskify[strlen(string)] = '\0';
    return maskify;
}

int main(void) {
    char *string = "sookaaaa1234";
    char *mask = maskify(string);
    printf("%s = %s\n", string, mask);
    free(mask);
    return 0;
}
