/*programm for modified newton raphson method*/
#include <stdio.h>
#include <math.h>
#define epsilon 1e-6
int main()
{
    /*This is a programm based on modified
newton raphson method to
find out root of the equation x^3-5*x^2+7*x-3=0*/
    double g, g1, v, v1, v2, x, dx;

    int converged = 0, i;
    printf("enter the guess value\n");
    scanf("%f", &g1);
    i = 1;
    while (converged == 0)
    {
        printf("\n iteration no=%d\n", i);
        v = g1 * g1 * g1 - 5 * g1 * g1 + 7 * g1 - 3;
        printf("v=%lf\n", v);
        v1 = 3 * g1 * g1 - 10 * g1 + 7;
        printf("v1=%lf\n", v1);
        v2 = 6 * g1 - 10;
        printf("v2=%lf\n", v2);
        x = (v * v1) / (v1 * v1 - v * v2);
        printf("value=%lf\n", x);
        g = g1 - ((v * v1) / (v1 * v1 - v * v2));
        printf("new guess is=%lf\n", g);
        dx = ((g - g1) / g);
        printf("error=%lf\n", dx);
        g1 = g;

        if (fabs(dx) < epsilon)
        {
            converged = 1;
        }
        printf("the root of equation is=%lf i=%d\n", g, i);
        i = i + 1;
    }
}
