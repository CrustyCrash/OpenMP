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



    // Without Reduction

    //  int sum[16];
    // int f_sum = 0;
    // omp_set_num_threads(16);
    // #pragma omp parallel 
    // {
    //     int ID = omp_get_thread_num();
    //     sum[ID] = 0;
    //     #pragma omp for
    //     for(int i = 1; i <= N; i++)
    //     {
    //         sum[ID] += i;
    //     }

    // }
    // for (int i = 0; i < 16; i++)
    // {
    //     f_sum += sum[i];
    // }
    // printf("%d\n",f_sum);

}
