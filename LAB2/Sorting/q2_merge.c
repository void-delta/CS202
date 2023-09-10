#include <stdio.h>
#include <time.h>

int k = 100000;

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		merge_sort(arr, l, m);
		merge_sort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

int main()
{
    int array[k];
    for(int i = 0; i < k; i++){
        array[i] = k - i;
    }

    clock_t t1;
    t1 = clock();
    merge_sort(array, 0, k - 1);
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