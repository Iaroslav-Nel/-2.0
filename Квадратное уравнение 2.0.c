#include <stdio.h>
#include <math.h>

int Solve (double a, double b, double c, double* x1, double* x2);

int main ()
{
    double a = 0;
    double b = 0;
    double c = 0;

    scanf ("%lg %lg %lg", &a, &b, &c);

    double x1 = 0;
    double x2 = 0;

    int Roots = Solve (a, b, c, &x1, &x2);

    switch (Roots)
    {

    case 0: printf ("no_roots\n");

            break;

    case 1: printf ("x = %lg\n", x1);

            break;

    case 2: printf ("x1 = %lg, x2 = %lg\n", x1, x2);

            break;
    }
}

int Solve (double a, double b, double c, double* x1, double* x2)
{

    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                printf ("you are stupid\n");
            }
            else
            {
                printf ("you are stupid too\n");
            }
        }
        else
        {
            printf ("x = %lg", -c / b);
        }
    }
    else
    {
        double d = b * b - 4 * a * c;

        if (d < 0)
        {
            printf ("d < 0\n");
        }

        else
        {
            if (d == 0)
            {
                *x1 = *x2 = -b / (2 * a);

                printf ("x = %lg\n", *x1);
            }
            else
            {
                *x1 = (-b + sqrt(d)) / (2 * a);
                *x2 = (-b - sqrt(d)) / (2 * a);

                printf ("x1 = %lg, x2 = %lg\n", *x1, *x2);
            }
        }
    }
}
