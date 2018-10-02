#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void crypted(int key, string word);

int main(int argc, string argv[])
{
    string plain;
    int k;

    if (argc == 2)
    {
        plain = get_string("plaintext: ");
        k = atoi(argv[1]);
    }
    else
    {
        printf("usage: k\n");
        return 1;
    }

    crypted(k, plain);
}

void crypted(int key, string word)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(word); i < n; i++)
    {

        if (word[i] >= 'a' && word[i] <= 'z')
        {
            printf("%c", 'a' + ((word[i] - 'a') + key) % 26);
        }
        else if (word[i] >= 'A' && word[i] <= 'Z')
        {
            printf("%c", 'A' + ((word[i] - 'A') + key) % 26);
        }
        else
        {
            printf("%c", word[i]);
        }
    }
    printf("\n");
}
