#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(int src, vector<int> adj[], vector<int> &visited, vector<int> &color)
{
    queue<int> q;
    q.push(src);
    visited[src] = 1;
    color[src] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto neighbor : adj[node])
        {
            if (visited[neighbor] == 1)
            {
                if (color[neighbor] == color[node])
                    return false;
            }
            else
            {
                visited[neighbor] = 1;
                color[neighbor] = 1 - color[node];
                q.push(neighbor);
            }
        }
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (!bfs(i, adj, visited, color))
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<int> adj[V];
    int u, v;
    for (int i = 0; i < E; i++)
    {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isBipartite(V, adj))
    {
        cout << "The graph is bipartite." << endl;
    }
    else
    {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
