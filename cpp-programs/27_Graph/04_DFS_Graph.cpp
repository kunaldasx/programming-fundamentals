// DFS in undirected and disconnected graph
#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>
#include <queue>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, set<int>> &adj, vector<int> &ans)
{
    // Store ans
    ans.push_back(node);
    // Mark visited
    visited[node] = true;

    // Make resursive call for every connected node
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, ans);
        }
    }
}

vector<vector<int>> depthFirstSearch(int vertex, vector<vector<int>> &edges)
{
    // Prepare adjacency List
    unordered_map<int, set<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // Call dfs for all nodes if it's not already visited
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{
    int vertex;
    cout << "Enter number of vertex: ";
    cin >> vertex;

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);

        edges.push_back(temp);
    }

    vector<vector<int>> ans = depthFirstSearch(vertex, edges);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}