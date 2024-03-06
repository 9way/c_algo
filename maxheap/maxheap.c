#include <stdio.h>


void heapify(int arr[], int n, int i)
{
    int temp;
    int right = (i << 1) + 2;
    int left = (i << 1) + 1;
    int max = i;

    if (left < n && arr[left] > arr[max])
    {
        max = left;
    }

    if (right < n && arr[right] > arr[max])
    {
        max = right;
    }

    if (max != i)
    {
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

        heapify(arr, n, max);
    }

    return;
}


void maxheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >=0; i--)
    {
        heapify(arr, n, i);
    }
}

int main(void)
{
    int arr[] = {20, 18, 5, 14, 3, 2, 1, 11, 19, 20};
    unsigned int n = 10;

    for (unsigned int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    maxheap(arr, n);

    printf("max heap: ");
    for (unsigned int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}