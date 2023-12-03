#include <stdio.h>
#include <time.h>

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void build_max_heap(int arr[], int N, int i){
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < N && arr[l] > arr[largest])
		largest = l;

	if (r < N && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(&arr[i], &arr[largest]);

		build_max_heap(arr, N, largest);
	}
}

void buildHeap(int arr[], int N){
	int startIdx = (N / 2) - 1;
	for (int i = startIdx; i >= 0; i--) {
		build_max_heap(arr, N, i);
	}
}

void printHeap(int arr[], int N){
	printf("Array representation of Heap is:\n");
	for (int i = 0; i < N; ++i)
		printf("%d ",arr[i]);
	printf("\n");
}

int main(){
	int k = 10;
    int arr[k];
    for(int i = 0; i < k; i++){
        arr[i] = i;
    }
    clock_t t1;
    t1 = clock();
	buildHeap(arr, k);    
    t1 = clock() - t1;
    double time1 = ((double)t1)/CLOCKS_PER_SEC;

	printHeap(arr, k);

    printf("Time taken: %f\n", t1);
	return 0;
}
