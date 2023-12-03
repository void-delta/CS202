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

void Kruskal(Edge *input, int num_vert, int num_edges){
    sort(input, input + num_edges, compare);

    Edge *output = new Edge[num_vert - 1];
    int *parent = new int[num_vert];

    for(int i = 0; i < num_vert; i++){
        parent[i] = i;
    }

    int i = 0, count = 0;
    while(count != num_vert - 1){
        Edge current_edge = input[i];

        int source_parent = findParent(current_edge.source, parent);
        int dest_parent = findParent(current_edge.destination, parent);

        if(source_parent != dest_parent){
            output[count] = current_edge;
            count++;
            parent[source_parent] = dest_parent;
        }
        i++;
    }

    int sum = 0;
    for(int j = 0; j < num_vert - 1; j++){
        sum += output[j].weight;
        cout << output[j].source << "->" << output[j].destination << " " << output[j].weight << "\n";
    }

    cout << "Cost of minimum spanning tree is " << sum;
}

int main(){
    int n, e;
    cin >> n >> e;

    Edge *input = new Edge[e];
    for(int i = 0; i < e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }

    Kruskal(input, n, e);
    return 0;
}