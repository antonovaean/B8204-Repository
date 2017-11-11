//
//  fibonacci.h
//  fibonacci
//
//  Created by macbook on 11.11.2017.
//  Copyright © 2017 macbook. All rights reserved.
//

#ifndef fibonacci_h
#define fibonacci_h

int getFib(int x)
{
    const int N=10;
    int FIB[N];
    
    if (x == 0 || x == 1) return x;
    if (x>N) return -1;
    {
        FIB[0]=1; FIB[1]=1;
        for (int i = 2; i <= x; i++ ){
        FIB[i]=FIB[i-1]+FIB[i-2];
    }
        return FIB[x];
    }
    
}

#endif /* fibonacci_h */
