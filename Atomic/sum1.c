#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>
#define N 10000

int main()
{
    srand(time(0));
    int a[N];
    int sum = 0;
    int serial_sum = 0;

    for (int i = 0; i < N; i++) 
    {
        a[i] = rand();
    }


    #pragma omp parallel for 
    for(int i = 0; i < N; i++)
    {   
        #pragma omp atomic
        sum += a[i]; 
    }
    
    for(int i = 0; i < N; i++)
    {
        serial_sum += a[i];
    }

    if(serial_sum != sum)
    {
        printf("Error!\n");
    }
    else
    {
        printf("Sum is same");
    }


}