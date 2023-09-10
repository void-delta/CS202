#include <math.h>
#include <stdio.h>
#include <time.h>

int k = 100000;

/* Function to sort an array using insertion sort*/
void insertion_sort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

/* Driver program to test insertion sort */
int main()
{
    int array[k];
    for(int i = 0; i < k; i++){
        array[i] = k - i;
    }
    clock_t t1;
    t1 = clock();
    insertion_sort(array, k);
    t1 = clock() - t1;
    double time1 = ((double)t1)/CLOCKS_PER_SEC;

    clock_t t2;
    t2 = clock();
    for(int i = 0; i < k; i++){
        printf("%d ", array[i]);
    }
    t2 = clock() - t2;
    double time2 = ((double)t2)/CLOCKS_PER_SEC;

    printf("\nSorting time: %f\nPrinting time: %f\n", time1, time2);
}
