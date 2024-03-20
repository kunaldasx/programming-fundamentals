// Shortest Path in a directed Graph with negative weights (Bellman Ford Algorithm)
#include <iostream>
#include <vector>
using namespace std;

int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // N-1 times
    for (int i = 1; i < n; i++)
    {
        // Traverse on edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != 1e9 && (dist[u] + w) < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    bool flag = false;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if (dist[u] != 1e9 && (dist[u] + w) < dist[v])
        {
            flag = true;
        }
    }

    if (flag == false)
    {
        return dist[dest];
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter number of vertex: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(w);

        edges.push_back(temp);
    }

    int src, dest;
    cout << "Enter source and destination: ";
    cin >> src >> dest;

    cout << "Shortest path from " << src << " to " << dest << ": " << bellmanFord(n, m, src, dest, edges) << endl;
    return 0;
}