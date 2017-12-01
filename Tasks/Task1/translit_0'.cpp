#include "translit_lib.h"
#include <stdio.h>
#include <locale.h>
#include <cstring>
#include <cstdlib>

char* kir = (char*) malloc(strlen("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя") + 1);
char lat[66][4] = {"A", "B", "V", "G", "D", "E", "Yo", "Zh", "Z", "I", "J", "K", "L",
                    "M", "N", "O", "P", "R", "S", "T", "U", "F", "H", "C", "Ch", "Sh",
                    "Sch", "\'\'", "Y", "\'", "E", "Ui", "Ya",
                    "a", "b", "v", "g", "d", "e", "yo", "zh", "z", "i", "j", "k", "l",
                    "m", "n", "o", "p", "r", "s", "t", "u", "f", "h", "c", "ch", "sh",
                    "sch", "\'\'", "y", "\'", "e", "ui", "ya"};

char* kirToLat(char c){
    int i(0);
    char res[4];
    while ((i < 66) && (kir[i] != c)) i++;
    if (i = 66) res = c;
    else res = lat[i];
    return res;
}

char* TranslitLib::translit(char* message){
    char* translitMess;
    for(int i = 0; i < sizeof(message)/sizeof(char); i++){
        translitMess[i] = kirToLat(message[i]);
    }
    return translitMess;
}

int main() {
    setlocale(LC_ALL, "russian");
    strcpy(kir, "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя");
    printf(TranslitLib::translit("Жопа"));
    return 0;
}