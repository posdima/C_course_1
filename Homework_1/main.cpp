#include<stdio.h>
//Pervoe dz. Programma rascheta po zadannym formulam

int main()
{
    float a=5, c=5, b, d;
    printf("a=%.0f, c=%.0f\n",a,c);
    printf("Enter variable b=");
    scanf("%f",&b);
    a=a+b-2;
    printf("a=%.0f\n",a);
    c=c+1;
    printf("c=%.0f\n",c);
    printf("Enter variable d=");
    scanf("%f",&d);
    d=c-a+d;
    printf("d=%.0f\n",d);
    a=a*c;
    printf("a=%.0f\n",a);
    c=c-1;
    printf("c=%.0f\n",c);
    a=a/10;
    printf("a=%.1f\n",a);
    c=c/2;
    printf("c=%.1f\n",c);
    b=b-1;
    printf("b=%.0f\n",b);
    d=d*(c+b+a);
    printf("d=%.1f\n",d);

    return 0;
}

