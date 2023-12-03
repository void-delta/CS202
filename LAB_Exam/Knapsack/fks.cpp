#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Item {
public:
    int no;
    int profit;
    int weight;
};

bool compare(Item j1, Item j2) {
    return j1.profit / j1.weight > j2.profit / j2.weight;
}

void greedy_knapsack(Item *items, int n_item, int weight) {
    int total_weight = 0;
    double gain = 0;
    int i = 0;
    int *final = new int[n_item];
    for (i = 0; i < n_item; i++) {
        final[i] = 0;
    }
    i = 0;
    while (total_weight < weight && i < n_item - 1) {
        total_weight += items[i].weight;
        gain += items[i].profit;
        final[i] = items[i].no;
        i++;
    }

    if (items[i].weight != 0) {
        gain += ((weight - total_weight) / items[i].weight) * items[i].profit;
        final[i] = items[i].no;
    }
    cout << "The total gain is " << gain << "\n";
    for (i = 0; i < n_item; i++) {
        cout << final[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n, w;
    cin >> n >> w;
    Item *input = new Item[n];
    cout << "N P W\n";
    for (int i = 0; i < n; i++) {
        int num, pr, weigh;
        cin >> num >> pr >> weigh;
        input[i].no = num;
        input[i].profit = pr;
        input[i].weight = weigh;
    }

    sort(input, input + n, compare);

    greedy_knapsack(input, n, w);

    delete[] input;

    return 0;
}
