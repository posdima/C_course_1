/*Дана строка символов. Получить из нее все слова нечетной длины.
Слова отделяются друг от друга одним пробелом*/

#include "word_delete.h"
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Enter the string of letters. To separate letters use ONE spacebar\n\n");
    char str[255];

    gets(str);

    if (strlen(str) == 0)
    {
        printf("You haven't entered the string of letters!");
        return -1;
    }

    wordDelete (str);

    return 0;
}
