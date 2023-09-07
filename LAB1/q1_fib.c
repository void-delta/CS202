#include <stdio.h>
#include <time.h>

void fibit(int n){
    int x = 0, y = 1;
    // int n = 10;
    printf("%d %d ", x, y);
    for(int i = 0; i < n; i++){
        int n = x + y;
        printf("%d ", n);
        x = y;
        y = n;
    }
    printf("\n");
}

int fibrec(int n){
    if(n < 2){
        return n;
    }
    else    
        return fibrec(n - 1) + fibrec(n - 2);
}

int main(){
    clock_t t1;
    t1 = clock();
    int n = fibrec(11);
    printf("%d\n", n);
    t1 = clock() - t1;
    double time1 = ((double)t1)/CLOCKS_PER_SEC;


    clock_t t2;
    t2 = clock();
    fibit(10);
    t2 = clock() - t2;
    double time2 = ((double)t2)/CLOCKS_PER_SEC;

    printf("Iteratively: %f seconds\nRecursively: %f seconds\n", time1, time2);
}