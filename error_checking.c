#include <stdio.h>
#ifdef _OPENMP
#include <omp.h>
#endif

int main(){
    int tid = 0;
    int total_threads = 0;
    #ifdef _OPENMP
    omp_set_num_threads(10);
    #endif
    #pragma omp parallel
    {
        #ifdef _OPENMP
        tid = omp_get_thread_num();
        total_threads = omp_get_num_threads();
        #endif

        printf("Thread id : %d  of %d\n",tid,total_threads);
    }
    return 0;
}