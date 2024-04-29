#include <stdio.h>
#include <omp.h>
#include <time.h>

int main()
{
    int a[1000];
    int b[1000];
    int c[1000];
    omp_set_num_threads(100);
    #pragma omp parallel for 
    for(int i = 0; i < 1000; i++)
    {
        a[i] = -i;
        b[i] = i + i;
    }

    #pragma omp barrier

    clock_t begin = clock();
    #pragma omp parallel for
    for(int i = 0; i < 1000; i++)
    {
        c[i] = a[i] + b[i];
    }
    //sleep(5);
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f",time_spent);


    for(int i = 0; i < 1000; i++)
    {
        printf("%d + %d = %d \n",a[i],b[i],c[i]);
    }    

}