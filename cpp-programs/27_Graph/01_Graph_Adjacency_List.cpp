// Implementation of Graph using Adjacency List
#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

template <typename T>
class graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        // direction = 0 ---> undirected
        // direction = 1 ---> directed

        // Create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void printAdList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    graph<int> g;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        // Creating an undirected graph
        g.addEdge(u, v, 0);
    }

    // Print graph
    g.printAdList();
    return 0;
}