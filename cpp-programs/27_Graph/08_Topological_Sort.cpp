// Topological Sort using DFS
// Topological Sort can only be applied on a Directed acyclic graph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;

void topologicalSortUtil(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
            topologicalSortUtil(neighbour, visited, s, adj);
    }

    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Create adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Call dfs topological sort util for all components
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 1; i <= v; i++)
    {
        if (!visited[i])
        {
            topologicalSortUtil(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
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

    vector<int> ans = topologicalSort(edges, vertex, e);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}