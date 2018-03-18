/**
 * helpers.h
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    while(n > 0)
    {
        n = n/2;
        if(values[n] == value)
        {
            return true;
        }
        else if(values[n] < value)
        {
            n = 1/2*n;
        }
        else if(values[n] > value)
        {
            n = 3/2*n;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int i;
    for(i = 0; i < (n - 1); i++)
    {
        int x;
        for(x = 0; x < n - i - 1; x++)
        {

            if(values[x] > values[x + 1])
            {
                int temp = values[x];
                values[x] = values[x + 1];
                values[x + 1] = temp;                                                             
            }
        }
    }
    return;
}

