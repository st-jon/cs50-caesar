#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void crypted(string key, string word);

int main(int argc, string argv[])
{
    string plain;

    if (argc == 2)
    {
        plain = get_string("plaintext: ");
    }
    else
    {
        printf("usage: k\n");
        return 1;
    }

    crypted(argv[1], plain);
}

void crypted(string key, string word)
{
    printf("ciphertext: ");
    int new_key;
    for (int i = 0, j = 0, n = strlen(word); i < n; i++)
    {

        new_key = toupper(key[j % strlen(key)]) - 65;

        if (word[i] >= 'a' && word[i] <= 'z')
        {
            printf("%c", 'a' + ((word[i] - 'a') + new_key) % 26);
            j++;
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            printf("%c", 'A' + ((word[i] - 'A') + new_key) % 26);
            j++;
        }
        else
        {
            printf("%c", word[i]);
        }


    }
    printf("\n");
}
