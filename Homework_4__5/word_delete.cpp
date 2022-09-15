#include "word_delete.h"
#include <stdio.h>
#include <string.h>

void wordDelete (char* str)
{
    char parse[255];
    int len = 0;

    while(str[len] != '\0')
    {
        sscanf(str + len, "%s", parse);
        const int wordLen = strlen(parse);
        len += wordLen + 1;

        if (wordLen % 2)
        {
            printf("%s ", parse);
        }
    }
}
