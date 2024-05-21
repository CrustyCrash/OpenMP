#include <omp.h>
#include <stdio.h>

int main()
{
    #pragma omp parallel sections num_threads(16) //this entire section will be executed by just 2 threads
    {
        #pragma omp section
        {
            printf("Section 1 executed by %d\n", omp_get_thread_num());
        }

        #pragma omp section
        {
            printf("Section 2 executed by %d\n", omp_get_thread_num());
        }
    }

    return 0;
}