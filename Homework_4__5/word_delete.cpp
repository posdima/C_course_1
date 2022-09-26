#include "word_delete.h"
#include <stdio.h>
#include <string.h>

void wordDelete(char* str)
{
    const int base_str_len = strlen(str);

    char* result = new char[base_str_len + 1]{};
    char* word = new char[base_str_len + 1]{};

    int len = 0;
    while(str[len] != '\0')
    {
        sscanf(str + len, "%s", word);
        const int wordLen = strlen(word);
        len += wordLen + 1;

        if (wordLen % 2)
        {
            if (strlen(result) != 0) {
                strncat(result, " ", base_str_len - strlen(result));
            }
            strncat(result, word, base_str_len - strlen(result));
        }
    }

    memcpy(str, result, base_str_len + 1);

    delete []word;
    delete []result;
}
