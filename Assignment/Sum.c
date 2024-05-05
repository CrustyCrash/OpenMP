//  Write an OpenMP program in c for calculating the sum of n natural
// numbers using OpenMP.
// Hint: #pragma omp barrier

#include <stdio.h>
#include <omp.h>
#define N 1000
int main()
{
    int arr[N];
    int sum = 0;
    //populating the array
    for (size_t i = 0; i < N; i++)
    {
        arr[i] = i+1;
    }
    #pragma omp parallel for reduction(+:sum)
    for(size_t i = 0; i < N; i++)
    {
        sum += arr[i];
    }

    printf("%d\n",sum);


}