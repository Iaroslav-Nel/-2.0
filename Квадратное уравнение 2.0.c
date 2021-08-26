#include <stdio.h>
#include <math.h>
#include <assert.h>
// !@#param [in] a      a - Coefficient
// !@#param [in] b      b - Coefficient
// !@#param [in] c      c - Coefficient
// !@#param [out] x1    x1 - First root (if the equation is square)
// !@#param [out] x2    x2 - Second root (if the equation is square)
// !@#param [out] x     x - The sole root (if the equation is linear or discriminant is equal to zero)

const int INF_ROOTS = -1;    //Introduce a constant for a situation with an infinite number of roots
const int NO_ROOTS  = -2;

int solvelinear (double a, double b, double c, double* x);
int solvesquare (double a, double b, double c, double* x1, double* x2, double* x);

int main (void)
{
    double a = 0, b = 0, c = 0;

    scanf ("%lg %lg %lg", &a, &b, &c);

    double x = 0, x1 = 0, x2 = 0;

    int nroots = solvesquare (a, b, c, &x1, &x2, &x);

    switch (nroots)          //Perform a check and make a conclusion in accordance with the number of roots
    {

    case 0: printf ("no_roots\n");

            break;

    case 1: printf ("x = %lg\n", x);

            break;

    case 2: printf ("x1 = %lg, x2 = %lg\n", x1, x2);

            break;

    default: break;
    }

    int nroots_2 = solvelinear (a, b, c, &x);

    switch (nroots_2)
    {
        case INF_ROOTS: printf ("%d\n", INF_ROOTS);

                        break;

        default: break;
    }
}

int solvelinear (double a, double b, double c, double* x)   //Introduce a function for solving a linear equation
{
    assert (isfinite (a));       //Perform a check on the finiteness of the numbers stored in variables
    assert (isfinite (b));
    assert (isfinite (c));

    if (fabs(a) < 1e-323)
    {
        if (fabs(b) < 1e-323)
        {
             if (fabs(c) < 1e-323)
             {
                 return INF_ROOTS;
             }
             else
             {
                 return INF_ROOTS;
             }
        }
        else
        {
             *x = -c / b;

             return 1;
        }
    }
    return NO_ROOTS;
}
int solvesquare (double a, double b, double c, double* x1, double* x2, double* x)  //Introduce a function for solving a square equation
{
    assert (isfinite (a));      //Perform a check on the finiteness of the numbers stored in variables
    assert (isfinite (b));
    assert (isfinite (c));

    if (fabs(a) < 1e-323)
    {
        solvelinear (a, b, c, x1, x2, x);

        return 1;
    }
    else

    {
    double d = b * b - 4 * a * c;

    if (d < 0)
    {
        return 0;
    }
    else
    {
        if (fabs(d) < 1e-323)
        {
            *x = -b / a;

            return 1;
        }
        else
        {
            *x1 = (-b + sqrt(d)) / (2 * a);
            *x2 = (-b - sqrt(d)) / (2 * a);

            return 2;
        }
    }
    }
}



