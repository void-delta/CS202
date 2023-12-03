#include <stdio.h>
#include <stdlib.h>

void fractionalKnapsack(int n, double *profits, double *weights, double capacity) {
    double *profitPerUnit = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        profitPerUnit[i] = profits[i] / weights[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profitPerUnit[j] < profitPerUnit[j + 1]) {
                double temp = profitPerUnit[j];
                profitPerUnit[j] = profitPerUnit[j + 1];
                profitPerUnit[j + 1] = temp;
                temp = profits[j];
                profits[j] = profits[j + 1];
                profits[j + 1] = temp;
                temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;
            }
        }
    }
    double totalProfit = 0.0;
    for(int i = 0; i < n; i++){
        if(capacity >= weights[i]){
            totalProfit += profits[i];
            capacity -= weights[i];
        } 
        else{
            totalProfit += (capacity / weights[i]) * profits[i];
            break; 
        }
    }
    printf("Maximum profit: %.2lf\n", totalProfit);
    free(profitPerUnit);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    double *profits = (double *)malloc(n * sizeof(double));
    double *weights = (double *)malloc(n * sizeof(double));
    printf("Enter the profits and weights for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%lf %lf", &profits[i], &weights[i]);
    }
    double capacity;
    printf("Enter the knapsack capacity: ");
    scanf("%lf", &capacity);
    fractionalKnapsack(n, profits, weights, capacity);
    free(profits);
    free(weights);

    return 0;
}
