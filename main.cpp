#include "functions.h"

int main(void)
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;

    printf("Quadratic equation solver\n"
           "Made by Ryabukhin Nikita\n2021\n\n");
    printf("Write coefficients a, b, c: \n");

    while(scanf("%lg%lg%lg", &a, &b, &c) != 3)
    {
      printf("Incorrect coefficients. "
             "Type must be double. "
             "Rewrite it, please:\n");
      scanf("%*[^\r^\n]");
    }

    Roots r_Num = SolveSquare(a, b, c, &x1, &x2);

    switch(r_Num)
    {
        case TWO_ROOTS:
          printf("There are x1 = %lg and x2 = %lg\n", x1, x2);
                break;
        case ONE_ROOT:
          printf("There is x = %lg\n", x1);
                break;
        case NO_ROOTS:
          printf("I`ve got no roots\n");
                break;
        case INF_ROOTS:
          printf("Any number fits\n");
                break;
        default:
          printf("main() ERROR: r_Num = %d\n", r_Num);
                return 1;
    }
    return 0;
}
