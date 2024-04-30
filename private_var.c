#include <stdio.h>
#include <omp.h>


int main(){
    int thread_id;
    #pragma omp private(thread_id)
    {
        printf("Printing from thread id %d \n",thread_id);
    }
}