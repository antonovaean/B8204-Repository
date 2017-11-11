#include "Header.h"
#include "stdafx.h"

int Fib(int pos) {
	static int n[30];
	int i;
	n[0] = 1;
	n[1] = 1;
	if (pos < (30 - 1)) {
		for (i = 2; i <= pos; i++) {
			n[i] = n[i - 1] + n[i - 2];
		}
		return n[i-1];
	}
	else {
		return -1;
	}
}