#include <stdio.h>
#include <omp.h>

int main(){
    int x = 10;
    int y = 20;

    omp_set_num_threads(4);
    #pragma omp parallel default(none) shared(x) shared(y)
    {
        x = omp_get_thread_num();
        printf("Thread %d: x = %d, y = %d ",omp_get_thread_num(), x , y);
    }
}