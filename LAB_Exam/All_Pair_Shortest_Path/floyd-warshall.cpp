#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define max 100000

void floyd_warshall(int **input, int n_ver, int n_edge){
    int dist[n_ver][n_ver];
    for(int i = 0; i < n_ver; i++){
        for(int j = 0; j < n_ver; j++){
            dist[i][j] = input[i][j];
        }
    }

    for(int i = 0; i < n_ver; i++){
        for(int j = 0; j < n_ver; j++){
            for(int k = 0; k < n_ver; k++){
                if(dist[i][k] == max || dist[k][j] == max)
                    continue;
                else if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }        
    }
    // if dist[i][i] is less than 0, then it has a negative weight cycle

    cout << "The All Pair Shortest path is\n";
    for(int i = 0; i < n_ver; i++){
        for(int j = 0; j < n_ver; j++){
            if(dist[i][j] == max)
                cout << "N ";
            else
                cout << dist[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    int **edges = new int*[n];

    for(int i = 0; i < n; i++){
        edges[i] = new int[n];
        for(int j = 0; j < n; j++){
            if(i == j)
                edges[i][j] = 0;
            else
                edges[i][j] = max;
        }
    }

    for(int i = 0; i < e; i++){
        int src, des, weigh;
        cin >> src >> des >> weigh;
        edges[src][des] = weigh;
    }

    floyd_warshall(edges, n, e);
}