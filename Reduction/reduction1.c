#include <stdio.h>
#include <omp.h>

#define N 1000

int main()
{
    int arr[N];
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        arr[i] = i;
    }

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    printf("%d", sum);
}