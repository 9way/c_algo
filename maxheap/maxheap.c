#include <stdio.h>

#define MAX 1000

void heapify(int arr[], unsigned int n, unsigned int i);


int pop(int arr[], unsigned int* size)
{
    int item;

    if ((*size) == 0) {
        printf("heap is empty.\n");
        return;
    }

    item = arr[0];

    arr[0] = arr[(*size) - 1];
    (*size)--;

    heapify(arr, (*size), 0);

    return item;
}


void printHeap(int arr[], unsigned int size)
{
    printf("size: %d\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void heapify(int arr[], unsigned int n, unsigned int i)
{
    int temp;
    unsigned int right = (i << 1) + 2;
    unsigned int left = (i << 1) + 1;
    unsigned int max = i;

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
    (*n)++;
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

    printf("Origin: ");
    printHeap(arr, n);

    maxheap(arr, n);

    printf("max heap: ");
    printHeap(arr, n);

    int key = 21;
    insertNode(arr, &n, key);

    printf("insert 21: ");
    printHeap(arr, n);


    printf("pop max: %d\n", pop(arr, &n));
    printHeap(arr, n);

    return 0;
}