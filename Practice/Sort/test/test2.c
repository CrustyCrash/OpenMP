#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel num_threads(2)
    for(int i = 0; i < 2; i++)
    {
        printf("Outer loop: Hello from thread %d\n", omp_get_thread_num());
        #pragma omp for
        for(int i = 0; i < 3; i++)
        {
            printf("Inner loop: Hello from thread %d\n", omp_get_thread_num());
        }
    }
}