#include "broken_telephone.h"

char* lineNodeNoise3(char *message, int messageLength)
{
    char s;
    int a = messageLength/2;

    s = message[a];
    message[a] = message[a+1];
    message[a+1] = s;

    return message;
}