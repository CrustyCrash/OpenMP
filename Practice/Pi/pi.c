#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char* argv[])
{
    double factor = 0.0;
    double sum = 0.0;
    int n;

    int thread_count = strtol(argv[1], NULL, 10);

    printf("Enter value of n \n");
    scanf("%d", &n);

    #pragma omp parallel for \
    reduction(+:sum) private(factor) num_threads(thread_count)

    for(int k = 0; k < n; k++)
    {
        if (k % 2 == 0)
            factor = 1;
        else
            factor = -1;
        
        sum += factor/(2*k + 1);

    }
    double pi_approx = 4 * sum;
    printf("pi = %.5e", pi_approx);
}