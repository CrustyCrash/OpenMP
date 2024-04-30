#include <stdio.h>
#include <omp.h>
#define N 100

int main()
{
    int arr[N];
    int sum = 0;

#pragma omp parallel num_threads(N)
    {
        int i = omp_get_thread_num();
        arr[i] = i + 1;

#pragma omp barrier
    
#pragma omp master
        {
            for (int j = 0; j < N; j++)
            {
                sum += arr[j];
            }
        }
    }
    printf("Sum is : %d", sum);
    return 0;
}