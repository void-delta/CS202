#include <stdio.h>

int maximum(int a, int b){
    if(a >= b){
        return a;
    } else {
        return b;
    }
    return 0;
}

void knapsack(int *weight, int *profit, int num, int max, int mat[num + 1][max + 1]){
    for(int i = 0; i <= num; i++){
        for(int w = 0; w <= max; w++){
            if(i == 0 || w == 0){
                mat[i][w] = 0; 
            }
            else if(weight[i - 1] <= w){
                mat[i][w] = maximum(mat[i - 1][w], mat[i -1][w - weight[i -1]] + profit[i - 1]);
            }
            else{
                mat[i][w] = mat[i - 1][w];
            }
        }
    }
    printf("The profit is %d", mat[num][max]);
}

int main(){
    int num;
    printf("Number of items available\t");
    scanf("%d", &num);
    int profit[num], weight[num];
    int max_weight;
    printf("What is the capacity of the knapsack\t");
    scanf("%d", &max_weight);
    printf("Enter the weight and profit of each item\n");
    for (int i = 0; i < num; i++) {
        printf("%d\t", i);
        scanf("%d %d", &weight[i], &profit[i]);
    }
    // sort(weight, profit, num);
    int matrix[num + 1][max_weight + 1];
    knapsack(weight, profit, num, max_weight, matrix);
    return 0;
}