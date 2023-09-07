#include <stdio.h>
#include <time.h>

int gcd_rec(int n1, int n2){
    if(n1%n2 == 0){
        return n2;
    }
    else
        return gcd_rec(n2, n1%n2);
}

int gcd_it(int n1, int n2){
    while(n1%n2 != 0){
        int temp = n1;
        n1 = n2;
        n2 = temp%n2;
    }
    return n2;
}

int main(){
    clock_t t1;
    t1 = clock();
    int n1 = gcd_it(774757, 56447);
    printf("%d\n", n1);
    t1 = clock() - t1;
    double time1 = ((double)t1)/CLOCKS_PER_SEC;


    clock_t t2;
    t2 = clock();
    int n2 = gcd_rec(774757, 56447);
    printf("%d\n", n2);
    t2 = clock() - t2;
    double time2 = ((double)t2)/CLOCKS_PER_SEC;

    printf("Iteratively: %f seconds\nRecursively: %f seconds\n", time1, time2);
}