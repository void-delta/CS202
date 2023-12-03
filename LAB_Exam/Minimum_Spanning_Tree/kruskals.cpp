#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

class Edge{
    public:
        int source;
        int destination;
        int weight;
};

int compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int index, int *array){
    if(array[index] == index){
        return index;
    }
    return findParent(array[index], array);
}

void kruskal_algo(Edge *input, int n, int edges){
    // sorting based on weight
    sort(input, input + edges, compare);

    Edge *output = new Edge[n - 1];
    int *parent = new int[n];

    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    int i = 0, count = 0;
    while(count != n - 1){
        // check if they are forming a cycle

        int source_parent = findParent(input[i].source, parent);
        int dest_parent = findParent(input[i].destination, parent);

        if(source_parent != dest_parent){
            output[count] = input[i];
            count++;
            parent[source_parent] = dest_parent;
        }
        i++;
    }

    int sum = 0;
    for(i = 0; i < n - 1; i++){
        cout << output[i].source << output[i].destination << output[i].weight << "\n";
        sum += output[i].weight;
    }
    cout << "The cost of the minimum spanning tree is " << sum << "\n";
}

int main(){
    int n, E;
    cin >> n >> E;
    Edge *input = new Edge[E];
    for(int i = 0; i < E; i++){
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }

    kruskal_algo(input, n, E);
    return 0;
}