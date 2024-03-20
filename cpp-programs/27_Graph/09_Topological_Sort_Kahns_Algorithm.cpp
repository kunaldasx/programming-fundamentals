// Topological Sort (Kahn's Algorithm) using BFS
// Topological Sort can only be applied on a Directed acyclic graph
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

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

    // Find all indegrees
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // Push all the nodes with 0 indegree into queue
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Do BFS
    vector<int> ans;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // Store ans
        ans.push_back(front);

        // Update indegree of Neighbour
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
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

    vector<int> ans = topologicalSort(edges, vertex, e);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}