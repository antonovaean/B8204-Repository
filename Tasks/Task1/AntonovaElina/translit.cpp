#include "Translit.h"

void translit(char* str)
{


	int i(0);

	while (str[i] != '\0')
	{

		switch (str[i])
		{
		case 'А': cout << "А"; break;
		case 'Б': cout << "B"; break;
		case 'В': cout << "V"; break;
		case 'Г': cout << "G"; break;
		case 'Д': cout << "D"; break;
		case 'Е': cout << "E"; break;
		case 'Ё': cout << "YE"; break;
		case 'Ж': cout << "J"; break;
		case 'З': cout << "Z"; break;
		case 'И': cout << "Y"; break;
		case 'Й': cout << "I"; break;
		case 'К': cout << "K"; break;
		case 'Л': cout << "L"; break;
		case 'М': cout << "M"; break;
		case 'Н': cout << "N"; break;
		case 'О': cout << "O"; break;
		case 'П': cout << "P"; break;
		case 'Р': cout << "R"; break;
		case 'С': cout << "S"; break;
		case 'Т': cout << "T"; break;
		case 'У': cout << "U"; break;
		case 'Ф': cout << "F"; break;
		case 'Х': cout << "H"; break;
		case 'Ц': cout << "TS"; break;
		case 'Ч': cout << "CH"; break;
		case 'Ш': cout << "SH"; break;
		case 'Щ': cout << "SCHI"; break;
		case 'Ъ': cout << ""; break;
		case 'Ы': cout << "II"; break;
		case 'Ь': cout << ""; break;
		case 'Э': cout << "E"; break;
		case 'Ю': cout << "U"; break;
		case 'Я': cout << "YA"; break;

		case 'а': cout << "a"; break;
		case 'б': cout << "b"; break;
		case 'в': cout << "v"; break;
		case 'г': cout << "g"; break;
		case 'д': cout << "d"; break;
		case 'е': cout << "e"; break;
		case 'ё': cout << "ye"; break;
		case 'ж': cout << "j"; break;
		case 'з': cout << "z"; break;
		case 'и': cout << "y"; break;
		case 'й': cout << "i"; break;
		case 'к': cout << "k"; break;
		case 'л': cout << "l"; break;
		case 'м': cout << "m"; break;
		case 'н': cout << "n"; break;
		case 'о': cout << "o"; break;
		case 'п': cout << "p"; break;
		case 'р': cout << "r"; break;
		case 'с': cout << "s"; break;
		case 'т': cout << "t"; break;
		case 'у': cout << "u"; break;
		case 'ф': cout << "f"; break;
		case 'х': cout << "h"; break;
		case 'ц': cout << "ts"; break;
		case 'ч': cout << "ch"; break;
		case 'ш': cout << "sh"; break;
		case 'щ': cout << "schi"; break;
		case 'ъ': cout << ""; break;
		case 'ы': cout << "y"; break;
		case 'ь': cout << ""; break;
		case 'э': cout << "e"; break;
		case 'ю': cout << "u"; break;
		case 'я': cout << "ya"; break;

			//Для вывода латиницы 
		case 'A': cout << "А"; break;
		case 'B': cout << "Б"; break;
		case 'C': cout << "С"; break;
		case 'D': cout << "Д"; break;
		case 'E': cout << "Е"; break;
		case 'F': cout << "Ф"; break;
		case 'G': cout << "Г"; break;
		case 'H': cout << "Х"; break;
		case 'I': cout << "И"; break;
		case 'J': cout << "ДЖ"; break;
		case 'K': cout << "К"; break;
		case 'L': cout << "Л"; break;
		case 'M': cout << "М"; break;
		case 'N': cout << "Н"; break;
		case 'O': cout << "О"; break;
		case 'P': cout << "П"; break;
		case 'Q': cout << "К"; break;
		case 'R': cout << "Р"; break;
		case 'S': cout << "С"; break;
		case 'T': cout << "Т"; break;
		case 'U': cout << "Ю"; break;
		case 'V': cout << "В"; break;
		case 'W': cout << "В"; break;
		case 'X': cout << "ИКС"; break;
		case 'Y': cout << "Й"; break;
		case 'Z': cout << "З";  break;


		case 'a': cout << "а"; break;
		case 'b': cout << "б"; break;
		case 'c': cout << "с"; break;
		case 'd': cout << "д"; break;
		case 'e': cout << "е"; break;
		case 'f': cout << "ф"; break;
		case 'g': cout << "г"; break;
		case 'h': cout << "х"; break;
		case 'i': cout << "и"; break;
		case 'j': cout << "дж"; break;
		case 'k': cout << "к"; break;
		case 'l': cout << "л"; break;
		case 'm': cout << "м"; break;
		case 'n': cout << "н"; break;
		case 'o': cout << "о"; break;
		case 'p': cout << "п"; break;
		case 'q': cout << "к"; break;
		case 'r': cout << "р"; break;
		case 's': cout << "с"; break;
		case 't': cout << "т"; break;
		case 'u': cout << "у"; break;
		case 'v': cout << "в"; break;
		case 'w': cout << "в"; break;
		case 'x': cout << "кс"; break;
		case 'y': cout << "й"; break;
		case 'z': cout << "з"; break;


		default:  cout << str[i];

		}
		i++;
	}
	return;
}