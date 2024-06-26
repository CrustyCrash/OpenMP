#include <stdio.h>
#include <stdlib.h>
#include <omp.h>


void trap(double a, double b, int n, double* gloal_result);

int main(int argc, char* argv[])
{
    double a;
    double b;
    int n; 
    double global_result = 0.0;
    int thread_count;

    thread_count = strtol(argv[1],NULL,10);
    printf("Enter a, b and n \n");
    scanf("%lf %lf %d", &a, &b, &n);

    #pragma omp parallel num_threads(thread_count)
    trap(a,b,n,&global_result);

    printf ( "With n = %d trapezoids , our estimate\n" , n ) ;
    printf ( "of the integral from %f to %f = %.14e\n" ,a , b , global_result ) ;
 
    return 0 ;
}

void trap(double a, double b, int n, double* global_result)
{
    double h;
    double x;
    double my_result;
    double local_a;
    double local_b;
    int i;
    int local_n;
    int my_rank = omp_get_thread_num();
    int thread_count = omp_get_num_threads();

    h = ( b - a ) / n ;

    local_n = n / thread_count ;
    local_a = a + my_rank * local_n *h ;
    local_b = local_a + local_n *h ;

    my_result = ((local_a) + (local_b))/2.0;

    for ( i = 1; i <= local_n - 1; i ++)
    {
    x = local_a + i * h ;
    my_result += (x) ;
    }

    my_result = my_result * h ;
    # pragma omp critical
    *global_result += my_result ;
}