// Write a C version of an OpenMP program that calculates the factorial
// of a given number.

#include <stdio.h>
#include <omp.h>

int main()
{
    int fact = 1;
    int num;
    printf("Enter to a number\n");
    scanf("%d",&num);

    #pragma omp parallel for reduction(*:fact)
    for (size_t i = 1; i <= num; i++)
    {
        fact = fact * i;
    }
    printf("Factorial is %d \n",fact);
}