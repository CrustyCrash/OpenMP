// Write a program that calculates for each array element the square of
// their index and stores it as the element value. These calculations
// must be done in parallel using OpenMP for.
// Expected output:
// a[0] = 0
// a[1] = 1
// a[2] = 4
// a[3] = 9
// a[4] = 16
// a[5] = 25

#include <stdio.h>
#include <omp.h>
#define N 100

int main()
{
    int squares[N];
    #pragma omp parallel for
    for (size_t i = 0; i < N; i++)
    {
        squares[i] = i * i;
    }

    for (size_t i = 0; i < N; i++)
    {
        printf("%d\n", squares[i]);
    }
}

