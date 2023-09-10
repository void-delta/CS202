#include <stdio.h>
#include <time.h>
int k = 100000;

int linear_search(int *arr, int key, int n){
    // int flag = 0;
    for(int i = 0; i < n; i++){
        if(*(arr + i) == key)
            return i;
        else
            continue;
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
    int n = linear_search(array, key, k);
    printf("Found at %d\n", n);
    t1 = clock() - t1;
    double time1 = ((double)t1)/CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", time1);
}
