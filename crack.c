#include <cs50.h>
#include <ctype.h>
#include <crypt.h>
#include <stdio.h>
#include <string.h>

#define _GNU_SOURCE



int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("usage: %s hash\n", argv[0]);
        return 1;
    }

    char *set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int set_length = strlen(set);

    char salt[3];
    salt[0] = argv[1][0];
    salt[1] = argv[1][1];

    char password[5];

    char test[5];


    for (int i = 0; i < set_length; i++)
        for (int j = 0; j < set_length; j++)
            for (int k = 0; k < set_length; k++)
                for (int l = 0; l < set_length; l++)
                    for (int m = 0; m < set_length; m++)
                    {
                        password[0] = set[i];
                        password[1] = set[j];
                        password[2] = set[k];
                        password[3] = set[l];
                        password[4] = set[m];

                        for (int n = 0, o = 5; n <= 4; n++, o--)
                        {
                            strncpy(test, password + n, o);
                            test[o] = '\0';
                            printf("...testing: %s\n", test);


                            if (strcmp(crypt(test, salt), argv[1]) == 0)
                            {
                                printf("Password found!\n%s\n", test);
                                return 0;
                            }

                        }

                    }
    printf("Nothing found :(\n");
    return 0;
}