#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int keylen = strlen(key);

    /* determine if key lenth is 26 characters */
    if (keylen != 26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    /* determine if key is valid */
    for (int i=0; i < keylen; i++)
    {
        if (key[i] < 65 || key[i] > 122)
        {
            printf("Key is not valid\n");
            return 1;
        }
        else if (key[i] > 90 && key[i] < 97)
        {
            printf("Key is not valid\n");
            return 1;
        }
    }
    /* determine if any repeating letters in key */
    int inst;

    for (int x=0; x < keylen; x++)
    {
        inst=0;
        for (int i=0; i < keylen; i++)
        {
            if (toupper(key[i]) == toupper(key[x]))
            {
                inst++;
            }
            if (inst > 1)
            {
                printf("Key has repeating characters\n");
                return 1;
            }
        }

    }
    /*
     printf("Valid key has been entered\n");
    */

    string plaintxt = get_string("plaintext: ");
    int plainlen = strlen(plaintxt);

    printf("ciphertext: ");

    for (int i=0; i < plainlen; i++)
    {
        if (plaintxt[i] > 64 && plaintxt[i]  < 91)
        {
            int loc = plaintxt[i] - 65;
            if (key[loc] > 96 && key[loc] < 123)
            {
            printf("%c", key[loc] - 32);
            }
            else
            {
             printf("%c", key[loc]);
            }
        }
        else if (plaintxt[i] > 96 && plaintxt[i]  < 123)
        {
            int loc = plaintxt[i] - 97;
            if (key[loc] > 64 && key[loc] < 91)
            {
            printf("%c", key[loc] + 32);
            }
            else
            {
             printf("%c", key[loc]);
            }
        }
        else
        {
            printf("%c", plaintxt[i]);
        }
    }

    printf("\n");
    return 0;
}

