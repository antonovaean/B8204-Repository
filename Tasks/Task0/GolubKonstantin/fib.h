//
// Created by c0di on 27.10.2017.
//

#ifndef UNTITLED_FIB_H
#define UNTITLED_FIB_H

int getFib(int x)
{
    if (x == 0 || x == 1) return x;
    else return getFib(x - 1) + getFib(x - 2);
}

#endif
