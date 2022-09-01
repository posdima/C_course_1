#include <math.h>
#include <stdio.h>
/*Программа, меняющая местами цифры старшего и младшего разрядов данного натурального числа
(например, из числа 3879 получится 9873)*/

int main()
{
    printf("Enter natural two-digit or more number: ");
    int number;
    scanf("%d", &number);

    if(number < 10)
    {
        printf("You have entered one-digit number!");
    }

    int last;
    last = number % 10;

    int first;
    first = number;

    int counter;
    counter = 0;

    while(first > 10)
    {
        first /= 10;
        ++counter;
    }

    number += (first - last) + (last - first) * pow(10, counter);

    printf("Converted number is: %d\n", number);

    return 0;
}
