#include <iostream>
using namespace std;

class Item{
    public:
        int profit;
        int weight;
};

int max(int a, int b){
    if(a >= b)
        return a;
    else
        return b;
}

void dynamic_knapsack(Item *it, int num, int wt, int **mat){
    for(int i = 0; i <= num; i++){
        for(int w = 0; w <= wt; w++){
            if(i == 0 || w == 0)
                mat[i][w] = 0;
            else if(it[i - 1].weight <= w) 
                mat[i][w] = max(mat[i - 1][w], mat[i - 1][w - it[i - 1].weight] + it[i - 1].profit);
            else
                mat[i][w] = mat[i - 1][w];
        }
    }
    cout << "The profit is " << mat[num][wt];
}

int main(){
    int n, w;
    cin >> n >> w;
    Item *items = new Item[n];
    for(int i = 0; i < n; i++){
        int pr, wt;
        cin >> pr >> wt;
        items[i].profit = pr;
        items[i].weight = wt;
    }
    int **mat = new int*[n + 1];
    for(int i = 0; i <= n; i++){
        mat[i] = new int[w + 1];
    }
    dynamic_knapsack(items, n, w, mat);
}