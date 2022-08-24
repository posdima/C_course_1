#include <stdio.h>
#include <math.h>

//DZ-2. Programma opredelenja ploscahdi figury i sravnenia ih mezhdu soboj

int main()
{
    double radius, triangle_side, square_side;
    double circle_square, triangle_square, square_area;

    printf("Enter circle radius R = ");
    scanf("%lf", &radius);
    circle_square = (M_PI) * pow(radius,2);
    printf("Circle square = %.2lf\n", circle_square);

    printf("Enter equilateral triangle side a = ");
    scanf("%lf", &triangle_side);
    triangle_square = ((pow(triangle_side,2))*sqrt(3))/4;
    printf("Equilateral triangle square = %.2lf\n", triangle_square);

    printf("Enter square side d = ");
    scanf("%lf", &square_side);
    square_area = pow(square_side,2);
    printf("Square area = %.2lf\n", square_area);

    (circle_square > triangle_square) ? (circle_square > square_area ? printf ("Circle ") : printf ("Square ")) : (
                triangle_square > square_area ? printf ("triangle ") : printf ("Square "));
        printf ("area is the biggest\n");

    return 0;
}
