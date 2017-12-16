#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include "translit_lib.h"

using namespace std;
//using namespace TranslitLib;

    char translit[33][4] = {"a","b","v","g","d","e","yo","zj","z","i","ia","k","l","m","n",
                            "o","p","r","s","t","u","f","h","c","ch","sh","sch","_","y",
                            "\'","yu","ya"};
    char rus[133] = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";
    //int key[strlen(message)];
    //char result[strlen(message)];


    char* cyrillicToLat(int fByte, int sByte) {
        int i(0);
        while ((i < 132) && (((int)rus[i] != fByte) || ((int)rus[i + 1] != sByte))) i+=2;
        if (i == 132) return '\0';
        else return translit[i/2];
    }

    char* TranslitLib::translit(char* message){
        char* result = new char[strlen(message) * 3];
        *result = {'\0'};
        char* symbol;
        for(int i = 0; i < strlen(message); i+=2){
            symbol = cyrillicToLat(message[i], message[i + 1]);
            if (symbol == NULL){
                strcat(result,  message);
            } else strcat(result, symbol);
        }
        return result;
    }
int main() {
    char* letter = (char*) malloc(strlen("дратути") + 1);
    strcpy(letter, "дратути");
    printf("%s ", TranslitLib::translit(letter));
    return 0;
}