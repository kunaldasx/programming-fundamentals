// Cycle detection in directed graph using BFS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

bool detectCycle(vector<pair<int, int>> &edges, int v)
{
    // Create adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

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
    for (int i = 1; i <= v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Do BFS
    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // Increment Count
        count++;

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

    if (count == v)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    int vertex;
    cout << "Enter number of vertex: ";
    cin >> vertex;

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<pair<int, int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }

    cout << detectCycle(edges, vertex) << endl;

    return 0;
}