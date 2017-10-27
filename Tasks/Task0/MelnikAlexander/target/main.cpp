#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SHOTS 5
#define MAX_ELLIPSES 5

typedef struct {
    double x, y;
} t_point;

double get_random_number(double, double);
void generate_shots(t_point[], size_t);

int main() {

    t_point shots[MAX_SHOTS];

    generate_shots(shots, MAX_SHOTS);

    printf("generated coords of shots:\n");
    for (int i = 0; i < MAX_SHOTS; i++)
        printf("  (%lf, %lf)\n", shots[i].x, shots[i].y);

    int score = 0;

    for (int i = 0; i < MAX_SHOTS; i++) {

        for (int j = 0; j < MAX_ELLIPSES; j++) {
            if (pow(shots[i].x, 2.) / pow(j+2, 2.) + pow(shots[i].y, 2.) / pow(j+1, 2.) < 1) {
                score += MAX_ELLIPSES - j;
                break;
            }
        }
    }

    printf("\nscore: %d\n", score);

    return 0;
}

double get_random_number(double a, double b) {
    return a + (rand() / (double) RAND_MAX) * (b - a);
}

void generate_shots(t_point shots[], size_t n) {
    srand( time(NULL) );

    for (int i = 0; i < n; i++) {
        shots[i].x = get_random_number(0.0, 6.0);
        shots[i].y = get_random_number(0.0, 6.0);
    }
}