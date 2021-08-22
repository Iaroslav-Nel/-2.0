#include <stdio.h>
#include <math.h>

main ()
{
    int a, b, c;

    scanf ("%d %d %d", &a, &b, &c);

    int d = sqrt(b * b - 4 * a * c);

    if ( d < 0 )
    {
        printf ("no KOßN");
    }
    else
    {
        float x = (-b + d) / (2 * a);

        float y = (-b - d) / (2 * a);

        printf (" %.2f  %.2f ", x, y);
    }

}
