#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S, vector<int> &parent)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distVect(V, INT_MAX);
    pq.push({0, S});
    distVect[S] = 0;
    parent[S] = -1;
    while (!pq.empty())
    {
        int edgeWeight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto &neighbor : adj[node])
        {
            int edgeNode = neighbor[0];
            int weight = neighbor[1];
            if (distVect[edgeNode] > edgeWeight + weight)
            {
                distVect[edgeNode] = edgeWeight + weight;
                pq.push({distVect[edgeNode], edgeNode});
                parent[edgeNode] = node;
            }
        }
    }
    return distVect;
}

void printPath(vector<int> parent, int node, stack<int> &st)
{
    if (node == -1)
        return;
    printPath(parent, parent[node], st);
    st.push(node);
}
int main()
{
    int V, E;
    cout << "Enter Number of Vertices and Edges:";
    cin >> V >> E;
    vector<vector<int>> adj[V];
    cout << "Enter Edges and Weights:";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int S;
    cout << "Enter Akshay's House Number:";
    cin >> S;
    vector<int> parent(V, -1);

    vector<int> distVect = dijkstra(V, adj, S, parent);

    cout << "Shortest Distance from Akshay's House to All Houses:\n";
    for (int i = 0; i < V; i++)
    {
        if (i == S)
            continue;
        if (distVect[i] == INT_MAX)
        {
            cout << "House Number: " << i << " is unreachable from Akshay's House\n";
        }
        else
        {
            cout << "House Number: " << i << " Distance: " << distVect[i] << " Path: ";
            stack<int> st;
            printPath(parent, i, st);
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
                if (!st.empty())
                    cout << " -> ";
            }
            cout << endl;
        }
    }
    return 0;
}
// 0 1 3 0 3 1 0 7 7 1 2 6 1 3 3 3 4 8 3 5 1 4 2 6 4 6 3 5 4 2 2 7 1