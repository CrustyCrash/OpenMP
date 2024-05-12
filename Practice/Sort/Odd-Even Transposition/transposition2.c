#include <stdio.h>
#include <omp.h>

void transposition(int [], int );

int main()
{
    int arr[] = {75, 10, 14, 28, 11, 7, 16, 30, 50, 25, 18};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }

    transposition(arr, size);

    printf("Sorted array: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ",arr[i]);
    }
}

void transposition(int arr[], int size)
{
    #pragma omp parallel num_threads(4)
    for(int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            #pragma omp for
            for(int k = 0; k < size; k +=2)
            {
                if (arr[k] > arr[k+1])
                {
                    int temp = arr[k];
                    arr[k] = arr[k+1];
                    arr[k+1] = temp;
                }
            }

        }
        else
        {
            #pragma omp for
            for(int k = 1; k < size-1; k+=2)
            {
                if (arr[k] > arr[k+1])
                {
                    int temp = arr[k];
                    arr[k] = arr[k+1];
                    arr[k+1] = temp;
                }
            }
        }
    }
    
}