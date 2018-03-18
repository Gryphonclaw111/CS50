#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float t;
    int count;
    int q = 0;
    int d = 0;
    int n = 0;
    int p = 0;
    do
    {
        printf("How much change is owed?");
        t = GetFloat();
    }
    while (t < 0.009);
    int c = round(t * 100);
    float roundf(float c);
    if (c == 25 || c > 25)
    {
        for (q = 0; c >= 25; q++)
        {
            c = c - 25;
        }
    }
    if (c == 24 || c < 24)
    {
        for (d = 0; c >= 10; d++)
        {
            c = c - 10;
        }
    }
    if (c == 9 || c < 9)
    {
        for (n = 0; c >= 5; n++)
        {
            c = c - 5;
        }
    }
    if (c == 4 || c < 4)
    {
        for (p = 0; c >= 1; p++)
        {
            c = c - 1;
        }
    }
    count = (q + d + n + p);
    printf("%i\n", count);
    
}
