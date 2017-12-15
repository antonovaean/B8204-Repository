#include "broken_telephone.h"
#include <stdio.h>
#include <iostream>

char* lineNodeNoise5(char *message, int messageLength) {
	char tmp;
	int ind1, ind2;
	for(int i = 0; i < 3; i++){
		ind1 = rand() % (messageLength - 1);
		ind2 = rand() % (messageLength - 1);
		tmp = message[ind1];
		message[ind1] = message[ind2];
		message[ind2] = tmp;
	}
	return message;
}

