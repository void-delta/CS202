#include <stdio.h>
#include <time.h>

int k = 100000;

void bubble_sort(int * arr, int len){
    int i = 0;
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                i = 1;
            }
            else
                continue;
        }
        if(i == 0){
            return;
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
    bubble_sort(array, k);
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