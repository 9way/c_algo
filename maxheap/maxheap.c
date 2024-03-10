#include <stdio.h>

#define MAX 1000


void printHeap(int arr[], int size)
{
    printf("size: %d\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


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

void _insertNode(int arr[], unsigned int index)
{
    unsigned parent = (index - 1) / 2;
    
    printf("parent: %d, index: %d\n", parent, index);
    if (arr[parent] < arr[index])
    {
        int tmp = arr[parent];
        arr[parent] = arr[index];
        arr[index] = tmp;

        if (parent > 0)
        {
            _insertNode(arr, parent);
        }
    }
}

void insertNode(int arr[], unsigned int* n, int Key)
{
    printf("%u\n", *n);
    *n += 1;
    arr[*n - 1] = Key;
    printf("%u\n", *n);
    printHeap(arr, *n);
    _insertNode(arr, *n - 1);
}


void maxheap(int arr[], unsigned int n)
{
    for (int i = n / 2 - 1; i >=0; i--)
    {
        heapify(arr, n, i);
    }
}

int main(void)
{
    int arr[MAX] = {20, 18, 5, 14, 3, 2, 1, 11, 19, 20};
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

    int key = 21;
    insertNode(arr, &n, key);

    printf("insert 21: ");
    for (unsigned int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}