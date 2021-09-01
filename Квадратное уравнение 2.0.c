#include <stdio.h>
#include <math.h>
#include <assert.h>

//! This function solves the square equation
//! @param [in] a      a - Coefficient
//! @param [in] b      b - Coefficient
//! @param [in] c      c - Coefficient
//! @param [out] x1    x1 - First root
//! @param [out] x2    x2 - Second root
//! @param [out] x     x - The sole root (if discriminant is equal to zero)
int solvesquare (double a, double b, double c, double* x1, double* x2);

//! This fuction solves the linear equation
//! @param [in] b      b - Coefficient
//! @param [in] c      c - Coefficient
//! @param [out] x     x - The sole root
int solvelinear (double b, double c, double* x1);

const int INF_ROOTS = -1;    //!< Introduce a constant for a situation with an infinite number of roots

int unity_test ();

int main (void)    //!< Declaring the main function
{
    double a = 0;
    double b = 0;
    double c = 0;
    
    if (scanf ("%lg %lg %lg", &a, &b, &c) < 3)
    {
        printf ("ERROR: were recorded less than 3 values");
    }
    else
    {
        double x1 = 0;
        double x2 = 0;

        int nroots = solvesquare (a, b, c, &x1, &x2);

        switch (nroots)      //!< Perform a check and make a conclusion in accordance with the number of roots
        {

            case 0: printf ("no roots\n");

                    break;

            case 1: printf ("x = %lg\n", x1);

                    break;

            case 2: printf ("x1 = %lg, x2 = %lg\n", x1, x2);

                    break;

            case INF_ROOTS: printf ("nroots = %d", INF_ROOTS);

                     break;

            default: printf ("ERROR");

                     break;
        }
    }
}
int solvelinear (double b, double c, double* x1)   //!< Introduce a function for solving a linear equation
{
    assert (isfinite (b));      //!< Perform a check on the finiteness of the numbers stored in variables
    assert (isfinite (c));

    assert (x1 != NULL);

    if (fabs(b) < 1e-20)
    {
        if (fabs(c) < 1e-20)
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
        *x1 = -c / b;

        return 1;
    }
}

int solvesquare (double a, double b, double c, double* x1, double* x2)  //!< Introduce a function for solving a square equation
{
    assert (isfinite (a));      //!< Perform a check on the finiteness of the numbers stored in variables
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    if (fabs(a) < 1e-20)
    {
        int root_of_solvelinear = solvelinear (b, c, x1);

        return root_of_solvelinear;
    }
    else
    {
        double d = b * b - 4 * a * c;

        if (fabs(d) < 1e-20)
        {
            *x1 = -b / (2 * a);

            return 1;
        }
        else
        {
            double dx = sqrt(d);

            *x1 = (-b + dx) / (2 * a);
            *x2 = (-b - dx) / (2 * a);

            return 2;
        }
    }
}

