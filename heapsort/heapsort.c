/*
    Some referenced from https://www.geeksforgeeks.org/heap-sort/
*/

#include <stdio.h>


void heapify(int arr[], unsigned int n, unsigned int i)
{
    unsigned int temp, max, left, right;

    max = i;
    right = (i << 1) + 2;
    left = (i << 1) + 1;

    // i_th node compared with its leaf
    if (left < n && arr[left] > arr[max])
    {
        max = left;
    }

    if (right < n && arr[right] > arr[max])
    {
        max = right;
    }

    // swap child and parrent if needed.
    // if swaped, heapify the sub-heap again.
    if (max != i)
    {
        temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

        heapify(arr, n, max);
    }
}


void heapsort(int arr[], unsigned int n)
{
    int i, temp;

    // heap leaf will be from (n / 2) to (n - 1)
    // process from bottom to top.
    // process non-leaf nodes to make min heap.
    // O(logn), worst O(n)
    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // O(n) * O(logn) == O(nlogn)
    for (int i = n - 1; i > 0; i--)
    {
        // max heap alway max item on 0th,
        // exchange it with leaf to re-arrange to ascending array
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        // max item is already in tails (arr[i]).
        // re-heap the 0th to (i-1)_th to max heap
        heapify(arr, i, 0);
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

    heapsort(arr, n);

    printf("sorted: ");
    for (unsigned int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}