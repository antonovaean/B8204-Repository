#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include "translit_lib.h"
//Пока почти работает для строк состоящих только из русских символов

char kir[133] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
char lat[66][4] = {"A", "B", "V", "G", "D", "E", "Yo", "Zh", "Z", "I", "J", "K", "L",
                    "M", "N", "O", "P", "R", "S", "T", "U", "F", "H", "C", "Ch", "Sh",
                    "Sch", "\'\'", "Y", "\'", "E", "Ui", "Ya",
                    "a", "b", "v", "g", "d", "e", "yo", "zh", "z", "i", "j", "k", "l",
                    "m", "n", "o", "p", "r", "s", "t", "u", "f", "h", "c", "ch", "sh",
                    "sch", "\'\'", "y", "\'", "e", "ui", "ya"};

char* cyrillicToLat(int fByte, int sByte){
    int i(0);
    while ((i < 132) && (((int)kir[i] != fByte) || ((int)kir[i + 1] != sByte))) i+=2;
    if (i == 132) return '\0';
    else return lat[i/2];
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
    char* mes = (char*) malloc(strlen("ПриветЩёДел") + 1);
    strcpy(mes, "ПриветЩёДел");

    printf("%s", TranslitLib::translit(mes));
    return 0;
}