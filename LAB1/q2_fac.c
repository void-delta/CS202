#include <stdio.h>
#include <time.h>

int fact_rec(int n){
    if(n == 1){
        return n;
    }
    else
        return n*fact_rec(n - 1);
}

int fact_it(int n){
    int factorial = n;
    for(int i = 1; i < n; i++){
        factorial = factorial*(n - i);
    }
    return factorial;
}

int main(){
    clock_t t1;
    t1 = clock();
    int n1 = fact_rec(24);
    printf("%d\n", n1);
    t1 = clock() - t1;
    double time1 = ((double)t1)/CLOCKS_PER_SEC;


    clock_t t2;
    t2 = clock();
    int n2 = fact_it(24);
    printf("%d\n", n2);
    t2 = clock() - t2;
    double time2 = ((double)t2)/CLOCKS_PER_SEC;

    printf("Iteratively: %f seconds\nRecursively: %f seconds\n", time2, time1);

}