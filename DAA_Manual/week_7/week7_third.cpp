#include <bits/stdc++.h>
using namespace std;
int dfs(vector<vector<pair<int, int>>> &adj, int node, int dest, int edges, vector<vector<int>> &dp)
{
    if (edges == 0)
    {
        return node == dest ? 0 : INT_MAX;
    }
    if (dp[node][edges] != -1)
    {
        return dp[node][edges];
    }
    int result = INT_MAX;
    for (auto p : adj[node])
    {
        int next = p.first;
        int weight = p.second;
        int subproblem = dfs(adj, next, dest, edges - 1, dp);
        if (subproblem != INT_MAX)
        {
            result = min(result, weight + subproblem);
        }
    }
    dp[node][edges] = result;
    return result;
}
int shortestPathWithKEdges(int V, vector<vector<pair<int, int>>> &adj, int src, int dest, int k)
{
    vector<vector<int>> memo(V, vector<int>(k + 1, -1));
    int result = dfs(adj, src, dest, k, memo);
    return (result == INT_MAX) ? -1 : result;
}
int main()
{
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    vector<vector<int>> edges;
    cout << "Enter edges and weights (u v w):\n";
    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    int src, dest, k;
    cout << "Enter source, destination and k: ";
    cin >> src >> dest >> k;
    int result = shortestPathWithKEdges(V, adj, src, dest, k);
    if (result == -1)
    {
        cout << "There is no path from " << src << " to " << dest << " with exactly " << k << " edges.\n";
    }
    else
    {
        cout << "The shortest path from " << src << " to " << dest << " with exactly " << k << " edges has weight " << result << ".\n";
    }
    return 0;
}
// 1 2 10 1 3 3 1 4 2 2 4 7 3 4 6
