#include <stdio.h>
#include <omp.h>

int main()
{
    int arr[] = {432,22,56,254,13,64,633,677,774,224,442,668};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maximum = 0;
    #pragma omp parallel for reduction(max:maximum)
    for(int i = 0; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }
    printf("%d",maximum);
}