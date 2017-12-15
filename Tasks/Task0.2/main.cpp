#include "broken_telephone.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    char str[] = "FEFU is my home 1234567890";
    int messageLen = (int) strlen(str);
    char *message = (char *) malloc(strlen(str) + 1);
    strcpy(message, str);

    message = lineNodeNoise1(message, messageLen);
    message = lineNodeNoise2(message, messageLen);
    message = lineNodeNoise3(message, messageLen);
    message = lineNodeNoise5(message, messageLen);
    message = lineNodeNoise6(message, messageLen);
    message = lineNodeNoise8(message, messageLen);

    printf("%s", message);
    return 0;
}
