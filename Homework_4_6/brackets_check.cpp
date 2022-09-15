#include "brackets_check.h"
#include <stdio.h>

int bracketsCheck(char *str)
{
    int i = 0;
    int counter = 0;

    while(str[i] != '\0')
    {
        if(str[i] == '(')
        {
            ++counter;
        }

        else if(str[i] == ')')
        {
            --counter;

            if(str[0] == ')')
            {
                printf("You've started with wrong bracket! First bracket should be ( !");
                return -1;
            }
        }

        ++i;
    }

    return counter;
}
