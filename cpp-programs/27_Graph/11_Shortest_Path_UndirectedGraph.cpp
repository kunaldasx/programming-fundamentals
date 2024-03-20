// Shortest Path in undirected graph (unweighted graph)
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> &edges, int src, int dest)
{
    // Create adjacency List
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS Traversal
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbour : adj[front])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = true;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }
    }

    //  Find the shortest path
    vector<int> ans;
    int currentNode = dest;
    ans.push_back(dest);

    while (currentNode != src)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());
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

    vector<pair<int, int>> edges;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));
    }

    int src, dest;
    cout << "Enter source and destination nodes: ";
    cin >> src >> dest;

    vector<int> ans = shortestPath(edges, src, dest);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}