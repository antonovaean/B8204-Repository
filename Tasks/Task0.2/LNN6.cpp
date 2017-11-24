#include "broken_telephone.h"
#include <stdio.h>
char* lineNodeNoise6(char *message, int messageLength){
char a;
for (int i=1; i<2; i++){
if (1 == i){
a=message[i];
} else {
message[i]=message[i-1];
message[i]=a;
}
}
return message;
}