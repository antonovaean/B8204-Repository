//
//  main.c
//  fibonacci
//
//  Created by macbook on 11.11.2017.
//  Copyright © 2017 macbook. All rights reserved.
//

#include "fibonacci.h"
#include <stdio.h>

int main()
{
    for (int i = 0; i < 10; ++i) printf("%d \n", getFib(i));
    return 0;
}
