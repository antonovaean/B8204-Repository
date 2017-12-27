#ifndef AFFINE_CYPHER_H
#define AFFINE_CYPHER_H

typedef char TCHAR;
typedef int TKEY;

/**
 * @link https://ru.wikipedia.org/wiki/Аффинный_шифр
 */
TCHAR* affine_cipher_encode(TCHAR* message);
TCHAR* affine_cipher_decode(TCHAR* message);

#endif //AFFINE_CYPHER_H
