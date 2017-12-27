#include "caesar_cipher.h"
#include <cstring>

TCHAR* caesar_cipher_encode(TCHAR* message, TKEY key){
    for(int i = 0; i < strlen(message); i++){
        message[i] = ((int)message[i] + key) % 256;
    }
    return message;
}
TCHAR* caesar_cipher_decode(TCHAR* message, TKEY key){
    for(int i = 0; i < strlen(message); i++){
        message[i] = ((int)message[i] - key) % 256;
    }
    return message;
}