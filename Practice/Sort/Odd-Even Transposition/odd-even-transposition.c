#include <stdio.h>
#include <omp.h>

void odd_even(int arr[], int n)
{
    int sorted = 0;
    while(!sorted)
    {
        sorted = 1;
        #pragma omp parallel for 
        for(int i = 1; i < n-1; i+=2)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = 0;
            }
 
                
        }

        #pragma omp parallel for
        for(int i = 0; i < n-1; i+=2)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                sorted = 0;
            }
        }
    
    }
}


int main()
{
    int arr[] = {75, 10, 14, 28, 11, 7, 16, 30, 50, 25, 18};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }

    odd_even(arr, size);

    printf("Sorted array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
}