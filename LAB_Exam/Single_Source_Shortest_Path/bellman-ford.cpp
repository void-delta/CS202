#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define max 100000

class Edges{
    public:
        int source;
        int destination;
        int weight;
};

void bellman_ford(Edges *edges, int n_ver, int n_edge, int source){
    int *parent = new int[n_ver];
    int *min_weight = new int[n_ver];
    for(int i = 0; i < n_ver; i++){
        min_weight[i] = max;
    }
    parent[source] = -1;
    min_weight[source] = 0;

    // we can use a boolean value called 'updated' 
    // to track if the negative weight cycle is present
    for(int i = 0; i < n_ver - 1; i++){
        for(int j = 0; j < n_edge; j++){
            int j_src = edges[j].source;
            int j_des = edges[j].destination;
            int j_wei = edges[j].weight;
            if(min_weight[edges[j].source] != max && min_weight[j_src] + j_wei < min_weight[j_des]){
                min_weight[j_des] = min_weight[j_src] + j_wei;
                parent[j_des] = j_src;
            }
        }
    } 

    cout << "The Single Source Shortest Path is \n";
    for(int i = 0; i < n_ver; i++){
        cout << min_weight[i] << " ";
    }
    cout << "\n";

}

int main(){
    int n, e;
    cin >> n >> e;
    Edges *input = new Edges[e];
    int k;
    cin >> k;

    for(int i = 0; i < e; i++){
        int src, des, weigh;
        cin >> src >> des >> weigh;
        input[i].source = src;
        input[i].destination = des;
        input[i].weight = weigh;
    }

    bellman_ford(input, n, e, k);
}