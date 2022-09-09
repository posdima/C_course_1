/*Дана строка символов. Удалить из нее все слова нечетной длины.
Слова отделяются друг от друга одним пробелом*/

#include<stdio.h>
#include<string.h>

int main()
{
    printf("Enter the string of letters. To separate letters use spacebar\n\n");
    char str[255];
    char parse[255];

    gets(str);

    int i = 0;
    int len;

    while(str[i] != '\0')
    {
        sscanf(str + i, "%s", parse);
        len = strlen(parse);
        i += (len + 1);

        if (len % 2 == 0)
        {
            continue;
        }

        else
            printf("%s ", parse);
    }

    return 0;
}
