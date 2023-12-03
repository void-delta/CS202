#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Item{
    public:
        int profit;
        int weight;
};

int maximum(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}

void dynamic_knapsack(Item *items, int n_item, int weight, int **matrix){
    for(int i = 0; i <= n_item; i++){
        for(int w = 0; w <= weight; w++){
            if(i == 0 || w == 0)
                matrix[i][w] = 0;
            else if(items[i - 1].weight <= w)
                matrix[i][w] = maximum(matrix[i - 1][w], matrix[i - 1][w - items[i - 1].weight] + items[i - 1].profit);
            else
                matrix[i][w] = matrix[i - 1][w];
        }
    }
    cout << "The profit is " << matrix[n_item][weight];
}

int main(){
    int n, w;
    cin >> n >> w;
    Item *items = new Item[n];
    for(int i = 0; i < n; i++){
        int pr, weigh;
        cin >> pr >> weigh;
        items[i].profit = pr;
        items[i].weight = weigh;
    }
    int **matrix = new int*[n + 1];
    for(int i = 0; i < n + 1; i++){
        matrix[i] = new int[w + 1];
    }
    dynamic_knapsack(items, n, w, matrix);
}