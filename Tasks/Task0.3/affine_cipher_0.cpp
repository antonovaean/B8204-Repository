#include "affine_cipher.h"
#include <cstring>

TCHAR* affine_cipher_encode(TCHAR* message){
    for(int i = 0; i < strlen(message); i++){
        message[i] = (3 * (int)message[i] + 19) % 256;
    }
    return message;
}
TCHAR* affine_cipher_decode(TCHAR* message){
    for(int i = 0; i < strlen(message); i++){
        message[i] = 171 * ((int)message[i] - 19) % 256;
    }
    return message;
}