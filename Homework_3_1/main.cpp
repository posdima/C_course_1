#include <stdio.h>
//Дано натуральное число N. Составить программу для определения количества цифр в этом числе.

int main()
{
    printf("Enter natural number N: ");
    int N;
    scanf("%d", &N);
    int counter = 0;

    while(N%10 != 0)
    {
        N/=10;
        counter++;
    }

    printf("N consists of %d numbers\n", counter);

    return 0;
}
