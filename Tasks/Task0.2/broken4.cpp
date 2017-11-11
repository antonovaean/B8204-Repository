#include <broken_telephone.h>
#include <stdio.h>

char* lineNodeNoise4(char *message, int messageLength) {
    char lel;
    int a, aa;
    int i=1;
    while (i<4){
    a = rand () % (messageLength - 1);
    aa = rand () % (messageLength - 1);
    lel = message [a]
    message [a] = message [aa];
    message [aa] = lel;
    i++;
}
return message;
}