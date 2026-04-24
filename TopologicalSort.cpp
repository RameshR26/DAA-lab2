#include <iostream>
#include <vector>
using namespace std;

void topoSort(int v, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result) {
    visited[v] = true;

    for(int i = 0; i < adj[v].size(); i++) {
        int next = adj[v][i];
        if(!visited[next])
            topoSort(next, adj, visited, result);
    }

    result.push_back(v);
}

int main() {
    int n = 6; // number of vertices

    vector<vector<int>> adj(n);

    // Given edges (Directed Graph)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<bool> visited(n, false);
    vector<int> result;

    for(int i = 0; i < n; i++) {
        if(!visited[i])
            topoSort(i, adj, visited, result);
    }

    cout << "Topological Sort:\n";
    for(int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << " ";

    return 0;
}