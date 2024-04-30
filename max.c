#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

int arr[10];
int n = sizeof(arr)/sizeof(arr[0]);

int main()
{
    int largest = 0;
    int pargest = 0;

    #pragma omp parallel for
    for(int i = 0; i<n; i++)
    {
        arr[i] = i + 20;
    }

    for(int i = 0; i<n; i++)
    {
        printf("%d\t",arr[i]);
    }

    for (int i = 1; i < n; i++){
            if (arr[i] > largest){
                largest = arr[i];
            }
    }
    printf("Largest by serial is %d\n",largest);


    #pragma omp parallel num_threads(100) shared(largest)
    {
        #pragma omp parallel for
        for (int i = 1; i < n; i++){
            if (arr[i] > pargest){
                pargest = arr[i];
            }
    }
    
}
    printf("Largest by parallel is %d\n",pargest);
}