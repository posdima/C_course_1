//Дана строка символов. Определить - является ли она правильным скобочным выражением

#include "brackets_check.h"
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Enter bracket expression using ( or ) brackets:\n");
    char str[255];

    gets(str);

    if (strlen(str) == 0)
    {
        printf("You haven't entered bracket expression");
        return 1;
    }

    for(int j = 0; str[j] != '\0'; ++j)
    {
        if(str[j] != '(' && str[j] != ')')
        {
            printf("Use only ( or ) brackets!");
            return 1;
        }
    }

    const int result = bracketsCheck(str);

    if(result == 0)
    {
        printf("It's correct bracket expression!");
    }

    else
    {
        printf("It's INcorrect bracket expression!");
    }

    return 0;
}
