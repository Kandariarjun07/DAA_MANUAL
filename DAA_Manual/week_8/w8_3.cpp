#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;

    for (int u = 0; u < V; ++u)
    {
        for (auto edge : adj[u])
        {
            int v = edge[0];
            int weight = edge[1];
            edges.push_back({weight, {u, v}});
        }
    }

    sort(edges.rbegin(), edges.rend());

    DisjointSet ds(V);
    int maxCost = 0;
    for (auto edge : edges)
    {
        int u = edge.second.first, v = edge.second.second, weight = edge.first;
        if (ds.findUPar(u) != ds.findUPar(v))
        {
            maxCost += weight;
            ds.unionBySize(u, v);
        }
    }

    return maxCost;
}

int main()
{
    int V = 7;
    vector<vector<int>> adj[V] = {
        {{2, 7}, {3, 5}},
        {{2, 8}, {3, 5}},
        {{0, 7}, {1, 8}, {3, 9}, {4, 7}},
        {{0, 5}, {1, 5}, {2, 9}, {4, 15}, {5, 6}},
        {{2, 7}, {3, 15}, {5, 8}, {6, 9}},
        {{3, 6}, {4, 8}, {6, 11}},
        {{4, 9}, {5, 11}}};

    int minCost = spanningTree(V, adj);
    cout << "Minimum cost required for road construction: " << minCost << endl;

    return 0;
}