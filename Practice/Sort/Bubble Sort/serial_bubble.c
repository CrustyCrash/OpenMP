#include <stdio.h>

int main()
{
    int array[] = {45,62,12,6,3,66,35,7,66,94,1,44,23,87,43};
    int size = sizeof(array)/sizeof(array[0]);

    for (int arr_size = size; arr_size >= 2; arr_size--)
    {
        for (int i = 0; i < arr_size -1 ; i++)
        {
            if (array[i] > array[i+1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
            }
        }
        
    }
    for(int i = 0; i < size; i++)
    {
        printf("%d\t",array[i]);
    }
}