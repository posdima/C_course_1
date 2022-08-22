#include <stdio.h>
#include <math.h>
// DZ- raschet po zadannoj formule

int main()
{
    double x,y;
    printf("Enter variable x = ");
    scanf("%lf", &x);

    y= ((2 * cos(x-(M_PI/6)) + sqrt(2))/((1/(2*logl(x))) + pow(sin(pow(x,2)),2))) * exp(3*x);
    printf("y=%.2lf", y);

    return 0;
}


