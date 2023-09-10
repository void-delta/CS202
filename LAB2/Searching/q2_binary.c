#include <stdio.h>
#include <time.h>
int k = 100000;

int binary_search(int *arr, int l, int r, int key){
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == key)
            return m;
        if (arr[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

void main(){
    int array[k];
    for(int i = 0; i < k; i++){
        array[i] = i;
    }
    int key;
    printf("Enter the key to be found\t");
    scanf("%d", &key);
    clock_t t1;
    t1 = clock();
    int n = binary_search(array, 0, k, key);
    printf("Found at %d\n", n);
    t1 = clock() - t1;
    double time1 = ((double)t1)/CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time1);
}