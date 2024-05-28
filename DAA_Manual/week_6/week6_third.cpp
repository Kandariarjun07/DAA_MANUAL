#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty())
    {
        int ele = q.front();
        q.pop();
        cnt++;
        for (auto it : adj[ele])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return cnt != V;
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
    }

    if (isCyclic(V, adj))
    {
        cout << "The graph contains a cycle." << endl;
    }
    else
    {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
