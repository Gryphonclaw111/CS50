#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        int k = atoi(argv[1]);
        string p = get_string();
    
        for(int i = 0, n = strlen(p); i < n; i++)
        {
            if (isalpha(p[i]))
            {
                if (isupper(p[i]))
                {
                    int alpha = p[i] - 65;
                    int c = (alpha + k) % 26;
                    printf("%c", c + 65);
                }
                else if (islower(p[i]))
                {
                    int beta = p[i] - 97;
                    int d = (beta + k) % 26;
                    printf("%c", d + 97);    
                }
            }
            else
            {
                printf("%c", p[i]);
            }
        }
    }
    else
    {
        printf("error");
        return 1;
        void exit(int status);
    }
    {
        printf("\n");
    }
}
