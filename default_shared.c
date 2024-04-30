#include <stdio.h>
#include <omp.h>

int main(){
    int x = 2;
    int y = 4;

    omp_set_num_threads(4);
    #pragma omp parallel default(shared) private(x,y)
    {
        printf("Initial value of x is: %d  Initial value of y is: %d \n",x,y);
        x = omp_get_thread_num();
        y=y+x;
        printf("Thread %d: x = %d y = %d \n",omp_get_thread_num(),x,y);
    }
    printf("Value outside --> Value of x: %d , Value of y: %d \n",x,y);

    return 0;
}