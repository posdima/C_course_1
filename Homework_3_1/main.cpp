#include <stdio.h>
//Дано натуральное число N. Составить программу для определения количества цифр в этом числе.

int main()
{
    printf("Enter natural number N: ");
    int N;
    scanf("%d", &N);
    int counter = 0;

    do
    {
        N /= 10;
        counter++;
    }
    while(N%10 != 0);

    printf("N consists of %d numbers\n", counter);

    return 0;
}
