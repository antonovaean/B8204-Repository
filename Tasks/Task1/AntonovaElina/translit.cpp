#include "Translit.h"

void translit(char* str)
{


	int i(0);

	while (str[i] != '\0')
	{

		switch (str[i])
		{
		case '�': cout << "�"; break;
		case '�': cout << "B"; break;
		case '�': cout << "V"; break;
		case '�': cout << "G"; break;
		case '�': cout << "D"; break;
		case '�': cout << "E"; break;
		case '�': cout << "YE"; break;
		case '�': cout << "J"; break;
		case '�': cout << "Z"; break;
		case '�': cout << "Y"; break;
		case '�': cout << "I"; break;
		case '�': cout << "K"; break;
		case '�': cout << "L"; break;
		case '�': cout << "M"; break;
		case '�': cout << "N"; break;
		case '�': cout << "O"; break;
		case '�': cout << "P"; break;
		case '�': cout << "R"; break;
		case '�': cout << "S"; break;
		case '�': cout << "T"; break;
		case '�': cout << "U"; break;
		case '�': cout << "F"; break;
		case '�': cout << "H"; break;
		case '�': cout << "TS"; break;
		case '�': cout << "CH"; break;
		case '�': cout << "SH"; break;
		case '�': cout << "SCHI"; break;
		case '�': cout << ""; break;
		case '�': cout << "II"; break;
		case '�': cout << ""; break;
		case '�': cout << "E"; break;
		case '�': cout << "U"; break;
		case '�': cout << "YA"; break;

		case '�': cout << "a"; break;
		case '�': cout << "b"; break;
		case '�': cout << "v"; break;
		case '�': cout << "g"; break;
		case '�': cout << "d"; break;
		case '�': cout << "e"; break;
		case '�': cout << "ye"; break;
		case '�': cout << "j"; break;
		case '�': cout << "z"; break;
		case '�': cout << "y"; break;
		case '�': cout << "i"; break;
		case '�': cout << "k"; break;
		case '�': cout << "l"; break;
		case '�': cout << "m"; break;
		case '�': cout << "n"; break;
		case '�': cout << "o"; break;
		case '�': cout << "p"; break;
		case '�': cout << "r"; break;
		case '�': cout << "s"; break;
		case '�': cout << "t"; break;
		case '�': cout << "u"; break;
		case '�': cout << "f"; break;
		case '�': cout << "h"; break;
		case '�': cout << "ts"; break;
		case '�': cout << "ch"; break;
		case '�': cout << "sh"; break;
		case '�': cout << "schi"; break;
		case '�': cout << ""; break;
		case '�': cout << "y"; break;
		case '�': cout << ""; break;
		case '�': cout << "e"; break;
		case '�': cout << "u"; break;
		case '�': cout << "ya"; break;

			//��� ������ �������� 
		case 'A': cout << "�"; break;
		case 'B': cout << "�"; break;
		case 'C': cout << "�"; break;
		case 'D': cout << "�"; break;
		case 'E': cout << "�"; break;
		case 'F': cout << "�"; break;
		case 'G': cout << "�"; break;
		case 'H': cout << "�"; break;
		case 'I': cout << "�"; break;
		case 'J': cout << "��"; break;
		case 'K': cout << "�"; break;
		case 'L': cout << "�"; break;
		case 'M': cout << "�"; break;
		case 'N': cout << "�"; break;
		case 'O': cout << "�"; break;
		case 'P': cout << "�"; break;
		case 'Q': cout << "�"; break;
		case 'R': cout << "�"; break;
		case 'S': cout << "�"; break;
		case 'T': cout << "�"; break;
		case 'U': cout << "�"; break;
		case 'V': cout << "�"; break;
		case 'W': cout << "�"; break;
		case 'X': cout << "���"; break;
		case 'Y': cout << "�"; break;
		case 'Z': cout << "�";  break;


		case 'a': cout << "�"; break;
		case 'b': cout << "�"; break;
		case 'c': cout << "�"; break;
		case 'd': cout << "�"; break;
		case 'e': cout << "�"; break;
		case 'f': cout << "�"; break;
		case 'g': cout << "�"; break;
		case 'h': cout << "�"; break;
		case 'i': cout << "�"; break;
		case 'j': cout << "��"; break;
		case 'k': cout << "�"; break;
		case 'l': cout << "�"; break;
		case 'm': cout << "�"; break;
		case 'n': cout << "�"; break;
		case 'o': cout << "�"; break;
		case 'p': cout << "�"; break;
		case 'q': cout << "�"; break;
		case 'r': cout << "�"; break;
		case 's': cout << "�"; break;
		case 't': cout << "�"; break;
		case 'u': cout << "�"; break;
		case 'v': cout << "�"; break;
		case 'w': cout << "�"; break;
		case 'x': cout << "��"; break;
		case 'y': cout << "�"; break;
		case 'z': cout << "�"; break;


		default:  cout << str[i];

		}
		i++;
	}
	return;
}