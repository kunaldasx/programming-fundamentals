// Dijkstra's Algorithm (Shortest Path)
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <climits>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Create adjancency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Creation of distance array with infinite value initially
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }

    // Creation of set on basis (distance, node)
    set<pair<int, int>> st;

    // Initialize distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0, source));

    while (!st.empty())
    {
        // Fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // Remove top record now
        st.erase(st.begin());

        // Traverse on neighbours
        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // If record found, then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                // Update distance
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // push record in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main()
{
    int vertex;
    cout << "Enter number of vertex: ";
    cin >> vertex;

    int e;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<vector<int>> vec;
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        vector<int> temp;
        temp.push_back(u);
        temp.push_back(v);
        temp.push_back(w);

        vec.push_back(temp);
    }

    vector<int> ans = dijkstra(vec, vertex, e, 0);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}