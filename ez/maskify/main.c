#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *maskify(const char s[]) {
    char *buf = (char *)malloc(strlen(s) * sizeof(char));
    for (int i = 0; i < strlen(s); i++) {
        if (i < strlen(s) - 4)
            buf[i] = s[i];
        else
            buf[i] = '#';
    }
    return buf;
}


int main(void) {
    char *mask_s = maskify("sooqa");
    printf("%s\n", mask_s);
    free(mask_s);
    return 0;
}
