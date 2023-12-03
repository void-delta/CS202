#include <stdio.h>
#include <time.h>

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

void heap_sort(int *arr, int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr, i, 0);
    }
}

void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int k = 10000;
    int array[k];
    for(int i = 0; i < k; i++){
        array[i] = i;
    }

    clock_t t1;
    t1 = clock();
    heap_sort(array, k);
    t1 = clock() - t1;
    double time1 = ((double)t1)/CLOCKS_PER_SEC;

    clock_t t2;
    t2 = clock();
    printArray(array, k);
    t2 = clock() - t2;
    double time2 = ((double)t2)/CLOCKS_PER_SEC;

    printf("\nSorting time: %f\nPrinting time: %f\n", time1, time2);
}
