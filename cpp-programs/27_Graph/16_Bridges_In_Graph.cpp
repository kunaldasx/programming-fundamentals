// Bridges in graph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &result, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = true;
    disc[node] = low[node] = timer++;

    for (auto neighbour : adj[node])
    {
        if (neighbour == parent)
        {
            continue;
        }
        if (!visited[neighbour])
        {
            dfs(neighbour, node, timer, disc, low, result, adj, visited);
            low[node] = min(low[node], low[neighbour]);
            // Check if edge is bridge
            if (low[neighbour] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
        {
            // Back Edge
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v); // Discovery Time
    vector<int> disc(v); // Lowest possible Discovery Time
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> visited;

    for (int i = 0; i < v; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // DFS
    vector<vector<int>> result;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, disc, low, result, adj, visited);
        }
    }
    return result;
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
        int u, v;
        cin >> u >> v;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);

        edges.push_back(temp);
    }

    vector<vector<int>> ans = findBridges(edges, n, m);
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