#include <iostream>
#include <stdlib.h>
using namespace std;

#define max 10000

int minWeighted(int *weight, bool *visited, int length) {
    int min_weight = max;
    int min_index = 0;
    for (int i = 0; i < length; i++) {
        if (!visited[i] && weight[i] < min_weight) {
            min_index = i;
            min_weight = weight[i];
        }
    }
    return min_index;
}

void prims_algo(int **edges, int num_vertex, int num_edges) {
    int *parent = new int[num_vertex];
    int *weight = new int[num_vertex];
    bool *visited = new bool[num_vertex];

    for (int i = 0; i < num_vertex; i++) {
        weight[i] = max;
        visited[i] = false;
    }
    weight[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < num_vertex - 1; i++) {
        // check the next shortest vertex which hasn't been visited
        int min_vertex = minWeighted(weight, visited, num_vertex);
        // now we make it visited
        visited[min_vertex] = true;
        // next we check for the shortest edge that doesn't make a cycle
        for (int j = 0; j < num_vertex; j++) {
            if (edges[min_vertex][j] && !visited[j] && edges[min_vertex][j] < weight[j]) {
                parent[j] = min_vertex;
                weight[j] = edges[min_vertex][j];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < num_vertex; i++) {
        sum += weight[i];
    }
    cout << "The cost of minimum spanning tree is " << sum;
}

int main() {
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];

    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }

    prims_algo(edges, n, e);
    
    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}
