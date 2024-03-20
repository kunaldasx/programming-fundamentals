// Count Strongly Connected Components (Kosaraju's Algorithm)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            dfs(neighbour, visited, st, adj);
        }
    }
    // Topo logic
    st.push(node);
}

void revdfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            revdfs(neighbour, visited, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Topo Sort
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    // Create Transpose Graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
        for (auto neighbour : adj[i])
        {
            transpose[neighbour].push_back(i);
        }
    }

    // DFS call using above ordering
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            count++;
            revdfs(top, visited, transpose);
        }
    }
    return count;
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

    cout << "Number of Strongly Connected Nodes: " << stronglyConnectedComponents(n, edges) << endl;

    return 0;
}