#include <stdio.h>
#include <omp.h>

int main()
{
    int sum = 0;
    int product = 1;
    #pragma omp parallel sections
    {
        #pragma omp section
        for(int i = 1; i <= 10; i++)
        {
            sum += i;
        }

        #pragma omp section
        for(int i = 1; i <= 10; i++)
        {
            product *= i;
        }

    }
    printf("Sum is %d\n",sum);
    printf("Product is %d\n",product);
}