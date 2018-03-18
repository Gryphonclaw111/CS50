#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string k = argv[1];
        for(int x = 0, u = strlen(k); x < u; x++)
        {
            if (isalpha(k[x]))
            {  
                printf("");
            }
            else
            {
                printf("error\n");
                return 1;
                void exit(int status);
            }
        }
        string p = get_string();
        for(int i = 0, n = strlen(p), z = 0; i < n; i++)
        {
            if (isalpha(p[i]))
            {
                int j = z % strlen(k);
                z++;
                if (isalpha(k[j]))
                {
                    if (isupper(k[j]))
                    {
                        if (isupper(p[i]))
                        {
                            int alpha = p[i] - 65;
                            int key = k[j] - 65;
                            int c = (alpha + key) % 26;
                            printf("%c", c + 65);
                        }
                        else if (islower(p[i]))
                        {
                            int beta = p[i] - 97;
                            int key = k[j] - 65;
                            int d = (beta + key) % 26;
                            printf("%c", d + 97);    
                        }
                    }
                    else if (islower(k[j]))
                    {
                        if (isupper(p[i]))
                        {
                            int alpha = p[i] - 65;
                            int key = k[j] - 97;
                            int c = (alpha + key) % 26;
                            printf("%c", c + 65);
                        }
                        else if (islower(p[i]))
                        {
                            int beta = p[i] - 97;
                            int key = k[j] - 97;
                            int d = (beta + key) % 26;
                            printf("%c", d + 97);    
                        }
                    }
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
        printf("error\n");
        return 1;
        void exit(int status);
    }
    {
        printf("\n");
    }
}
