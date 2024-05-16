#include <stdio.h>
#include <omp.h>

#define N 100

int isPrime(int count)
{
    int flag = 0;
   // int count = 0;
    #pragma omp parallel for reduction (+:count) 
    for(int i = 4; i < N; i++)
    {
       flag = 0;
       for(int j = 2 ; j <= i/2; j++ )
       {
        if (i % j == 0)
        {
            flag = 1;
            break;
        }
       }
       if(flag == 0)
       {
        printf("%d\n", i);
        count = count + 1;
       }
    }
    return count;
}

int main()
{
    printf("%d", 2 + isPrime(0));
}