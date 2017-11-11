#include "broken_telephone.h"
#include <stdio.h>
char char* lineNodeNoise6(char *message, int messageLength){
char a;
for (int i=1; i<2; i++){
if (i=1){
a=message[i];
} else {
message[i]=message[i-1];
message[i]=a;
}
}
return *message
}