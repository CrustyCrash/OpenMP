#include <stdio.h>
#include <omp.h>

int main(){
    int x = 20;
    int y = 30;
    #pragma omp parallel num_threads(4) default(shared) private(x)
    {
        printf("Value of x is : %d\n\n",x);
        x = omp_get_thread_num();
        printf("Value of x is %d\n",x);
    }
    return 0;
}