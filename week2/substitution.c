#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2 || strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    char newAlph[26];
    char key[26];

    for (int i = 0; i < 26; i++)
    {
        key[i] = toupper(argv[1][i]);
        if (key[i] >= 65 && key[i] <= 90)
        {
            newAlph[i] = 65 + i - key[i];
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        for (int j = 0; j < i; j++)
        {
            if (key[i] == key[j])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    string text = get_string("plaintext: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 65 && text[i] <= 90)
        {
            text[i] = text[i] - newAlph[text[i] - 65];
        }
        else if (text[i] >= 97 && text[i] <= 122)
        {
            text[i] = text[i] - newAlph[text[i] - 97];
        }
    }

    printf("ciphertext: %s\n", text);
    return 0;
}
