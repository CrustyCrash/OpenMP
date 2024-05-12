#include <stdio.h>
#include <omp.h>

int main()
{
    #pragma omp parallel for num_threads(4)
  
        for(int i = 0; i < 5; i++)
        {
            printf("Hello from thread %d\n",omp_get_thread_num());
        }
    
}