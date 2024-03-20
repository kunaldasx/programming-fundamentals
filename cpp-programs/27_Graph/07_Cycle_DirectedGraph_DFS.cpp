// Cycle detection in directed graph using DFS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, visited, dfsVisited, adj);
            if (cycleDetected)
            {
                return true;
            }
        }
        // Visited[neighbour] --- True && dsfVisited[neighbour] --- True
        // Cycle Detected
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool cycleDetection(vector<pair<int, int>> &edges, int n)
{
    // Create adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // Call DFS for all disconnected components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool cycleDetected = isCyclicDFS(i, visited, dfsVisited, adj);
            if (cycleDetected)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n;
    cout << "Enter number of vertex: ";
    cin >> n;

    int m;
    cout << "Enter number of edges: ";
    cin >> m;

    vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }

    cout << cycleDetection(edges, n) << endl;
    return 0;
}