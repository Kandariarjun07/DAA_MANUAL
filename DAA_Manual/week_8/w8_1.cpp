#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V, false);
    pq.push({0, 0});
    int ans = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        int wt = p.first;
        int node = p.second;
        pq.pop();
        if (visited[node])
            continue;
        visited[node] = true;
        ans += wt;
        for (auto &neighbor : adj[node])
        {
            int adjNode = neighbor[0];
            int edgeWeight = neighbor[1];
            if (!visited[adjNode])
            {
                pq.push({edgeWeight, adjNode});
            }
        }
    }
    return ans;
}

int main()
{
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> adj[V];
    int E;
    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges in the format (source destination weight):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int minCost = spanningTree(V, adj);
    cout << "Minimum cost required for road construction: " << minCost << endl;

    return 0;
}
// 7 11 0 2 7 2 4 7 0 3 5 1 2 8 1 3 5 2 3 9 3 5 6 4 5 8 4 3 15 4 6 9 5 6 11