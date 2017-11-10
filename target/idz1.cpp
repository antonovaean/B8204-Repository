#include <stdio.h>

bool inEllipse(double x, double y, int a, int b) {
    return ((x * x) / (a * a) + (y * y) / (b * b)) <= 1.0;
}

int main()
{
    double x, y;
    short int r = 0, w, h;
    w = 5;	h = 4;
    scanf("%lf %lf", &x, &y);
    printf("%.2f %.2f\n", x, y);
    for (int i = 0; i < h; i++)	
        if (inEllipse(x, y, w - i, h - i)) r++;
    printf("Result = %i\n", r);
    
    return 0;
}