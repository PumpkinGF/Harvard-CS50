#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substituion key\n");
        return 1; // 报错return 1
    }

    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    char key[26]; // 考虑key大小写情况
    for (int j = 0; j < 26; j++)
    {
        key[j] = argv[1][j];

        // 如果key里有非letter的情况，报错
        if (key[j] < 'A' || (key[j] > 'Z' && key[j] < 'a') || key[j] > 'z')
        {
            printf("Key is invalid\n");
            return 1;
        }
        else
        {
            key[j] = toupper(argv[1][j]);
        }
    }

    // check for duplicates in key
    for (int n = 0; n < 26; n++)
    {
        for (int m = n + 1; m < 26; m++)
        {
            if (key[n] == key[m])
            {
                printf("Duplicates in key\n");
                return 1;
            }
        }
    }

    string plaintext = get_string("plaintext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // char plainchar = (char) plaintext[i];
        if ((plaintext[i] <= 'Z') && (plaintext[i] >= 'A'))
        {
            plaintext[i] = key[plaintext[i] - 'A'];
        }
        else if ((plaintext[i] <= 'z') && (plaintext[i] >= 'a'))
        {
            plaintext[i] = key[plaintext[i] - 'a'] - 'A' + 'a';
        }
    }
    printf("ciphertext: %s\n", plaintext);
}