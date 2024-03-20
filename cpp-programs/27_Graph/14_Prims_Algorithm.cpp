// Minimum Spanning tree (Prim's Algorithm)
// 1 2 2
// 1 4 6
// 2 4 8
// 2 5 5
// 2 3 3
// 3 5 7
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <climits>
using namespace std;

vector<pair<pair<int, int>, int>> MST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;  // src
        int v = g[i].first.second; // dest
        int w = g[i].second;       // weight

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 1; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // Algo start
    key[1] = 0;

    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;
        // Find the minimum value from key vector
        for (int j = 1; j <= n; j++)
        {
            if (mst[j] == false && key[j] < mini)
            {
                u = j;
                mini = key[j];
            }
        }

        // Mark min node as true
        mst[u] = true;

        // Check its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
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

    vector<pair<pair<int, int>, int>> g;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.push_back({{u, v}, w});
    }

    vector<pair<pair<int, int>, int>> result = MST(n, m, g);

    for (auto i : result)
    {
        cout << i.first.first << "-" << i.second << "-" << i.first.second << endl;
    }
    return 0;
}
