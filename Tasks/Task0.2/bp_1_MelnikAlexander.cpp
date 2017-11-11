#include "broken_telephone.h"
#include <iostream> // for rand()

int getRandomNumber(int a, int b) {
    // return random number from a to b inclusive

    return rand() % (b - a + 1) + a;
}

char* lineNodeNoise1(char *message, int messageLength) {

    int i = getRandomNumber(0, messageLength - 1);
    int j = getRandomNumber(0, messageLength - 1);

    char tmp = message[i];
    message[i] = message[j];
    message[j] = tmp;

    return message;
}
