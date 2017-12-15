#include "broken_telephone.h"

char* lineNodeNoise2(char *message, int messageLength) {
    char m = message[1];
    if (messageLength <= 7) {
        message[1] = message[5];
        message[5] = m;
    }
    return message;
}

