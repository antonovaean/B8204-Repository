#ifndef CAESAR_CYPHER_H
#define CAESAR_CYPHER_H

typedef char TCHAR;
typedef int TKEY;

/**
 * @link https://ru.wikipedia.org/wiki/Шифр_Цезаря
 */
TCHAR* caesar_cipher_encode(TCHAR* message, TKEY key);
TCHAR* caesar_cipher_decode(TCHAR* message, TKEY key);

#endif //CAESAR_CYPHER_H
