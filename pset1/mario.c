#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size;

    do
    {
        size = get_int("Height: ");
    }
    while (size < 1 || size > 8);

    for (int i = 1; i < size+1; i++)
    {
        for (int j = size-i-1; j > -1; j--)
        {
            printf(" ");
        }
        for (int k = 1; k < i+1; k++)
        {
            printf("#");
        }
        printf(" ");
        for (int l = 1; l < i+1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}