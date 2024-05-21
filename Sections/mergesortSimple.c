#include <stdio.h>

void mergeSort(int arr[], int low, int mid, int high)
{
    int temp_arr[100];
    int left = low;
    int right = mid+1;
    int k = low;

    while( left<=mid && right<=high)
    {
        if(arr[left] < arr[right])
        {
            temp_arr[k] = arr[left];
            k++;
            left++;
        }
        else
        {
            temp_arr[k] = arr[right];
            k++;
            right++;
        }
    }

    while(left <= mid)
    {
        temp_arr[k] = arr[left];
        left++;
        k++;
    }

    while(right <= high)
    {
        temp_arr[k] = arr[right];
        k++;
        right++;
    }

    for(int i = low; i <= high; i++)
    {
        arr[i] = temp_arr[i];
    }
}

void merge(int arr[], int low, int high)
{
    if (low >= high)
    {   
        return;
    }

    int mid = low + ((high-low)/2);
    merge(arr,low,mid);
    merge(arr,mid+1,high);
    mergeSort(arr,low, mid, high);
}

int main()
{
    int arr[10] = {23,55,12,76,45,99,34,8,48,21};
    int size = sizeof(arr)/sizeof(arr[0]);

    merge(arr,0,size-1);

    for(int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}