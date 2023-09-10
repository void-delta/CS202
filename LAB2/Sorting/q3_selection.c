#include <stdio.h>
#include <time.h>

int k = 100000;

void selection_sort(int *arr, int len){
    int i, j, min_index;
    for(int i = 0; i < len; i++){
        min_index = i;
        for(int j = i; j < len; j++){
            if(*(arr + j) < *(arr + min_index)){
                min_index = j;
            }
        }
        if(min_index != i){
            int temp = *(arr + i);
            *(arr + i) = *(arr + min_index);
            *(arr + min_index) = temp;
        }
    }
}

void main(){
    int array[k];
    for(int i = 0; i < k; i++){
        array[i] = k - i;
    }
    clock_t t1;
    t1 = clock();
    selection_sort(array, k);
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
