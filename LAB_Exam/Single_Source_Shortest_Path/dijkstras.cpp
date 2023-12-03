#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define max 10000

int findMinVertex(int **edges, bool *visited, int *distance, int n_ver){
    int min = max, min_index = 0;
    for(int i = 0; i < n_ver; i++){
        if(!visited[i] && distance[i] < min){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int **edges, int n_ver, int n_edge, int source){
    // we assume that the source is 0
    int *min_dist = new int[n_ver];
    bool *visited = new bool[n_ver];
    for(int i = 0; i < n_ver; i++){
        min_dist[i] = max;
        visited[i] = false;
    }
    min_dist[source] = 0;

    for(int i = 0; i < n_ver; i++){
        int min_vertex = findMinVertex(edges, visited, min_dist, n_ver);
        visited[min_vertex] = true;
        for(int j = 0; j < n_ver; j++){
            if(!visited[j] && edges[min_vertex][j] != 0){
                int relax_dist = min_dist[min_vertex] + edges[min_vertex][j];
                if(min_dist[j] > relax_dist){
                    min_dist[j] = relax_dist;
                }
            }
        }
    }

    cout << "The Single Source Shortest Path is \n";
    for(int i = 0; i < n_ver; i++){
        cout << min_dist[i] << " ";
    }
    cout << "\n";
}

int main(){
    int n, e;
    cin >> n >> e;
    int k; // the source input
    cin >> k;
    int **edges = new int*[n];
    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0; i < e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }

    dijkstra(edges, n, e, k);
}