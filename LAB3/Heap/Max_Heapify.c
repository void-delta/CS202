#include <stdio.h>

void maxHeapify(int arr[], int n, int i) {
    int largest = i; 
    int leftChild = 2 * i + 1; 
    int rightChild = 2 * i + 2; 
    if (leftChild < n && arr[leftChild] > arr[largest])
        largest = leftChild;
    if (rightChild < n && arr[rightChild] > arr[largest])
        largest = rightChild;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d ", &arr[i]);
    }

    printf("Original array: \n");
    printArray(arr, n);
    int i = 0;
    maxHeapify(arr, n, i);

    printf("Heapified array: \n");
    printArray(arr, n);

    return 0;
}
