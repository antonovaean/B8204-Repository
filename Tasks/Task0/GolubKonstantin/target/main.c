#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double HEIGHT = 4;
const double WIDTH = 5;
const int SCORE_FOR_CIRCLE = 10;
const int ATTEMPT = 1;

int target(double width, double height, double x, double y)
{
    double min = (height > width) ? width : height;
    if (min < 0) return 0;

    double ellipse = sqrt(x) / sqrt(width) + sqrt(y) / sqrt(height);
    if (ellipse > 1) return 0; //Вышли из эллипса
    else if (ellipse == 1) return SCORE_FOR_CIRCLE; //На границе элипса
    else return SCORE_FOR_CIRCLE + target(width - 1, height - 1, x, y); //Вошли в эллипсе
}

void printRank(int score)
{
    int min = (int) ((HEIGHT > WIDTH) ? WIDTH : HEIGHT);
    int maxScore = SCORE_FOR_CIRCLE * (min + 1) * ATTEMPT;
    float percent = (float) score / (float) maxScore * 100.0f;

    if (percent < 30.0f) printf("Rank: bad\n");
    else if (percent < 50.0f) printf("Rank: good\n");
    else if (percent < 70.0f) printf("Rank: excellent\n");
    else if (percent < 100.0f) printf("Rank: perfect\n");
    else if (percent <= 100.0f) printf("Rank: who are you?\n");
}

int main()
{
    int score = 0;

    for (int i = 0; i < ATTEMPT; ++i) score += target(WIDTH, HEIGHT, rand() % 6, rand() % 6);

    printRank(score);
    printf("Score: %d\n", score);

    return 0;
}

