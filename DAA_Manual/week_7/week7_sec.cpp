#include <bits/stdc++.h>
using namespace std;

void printPath(vector<int> &parent, int node, stack<int> &st)
{
    if (node == -1)
        return;
    printPath(parent, parent[node], st);
    st.push(node);
}

bool isNegativeCycle(vector<vector<int>> &edges, vector<int> &dist)
{
    for (auto edge : edges)
    {
        int from = edge[0];
        int to = edge[1];
        int wt = edge[2];
        if (dist[from] != INT_MAX)
        {
            if (dist[from] + wt < dist[to])
            {
                return true;
            }
        }
    }
    return false;
}

bool bellmanFord(int V, vector<vector<int>> &edges, int S, vector<int> &distVect, vector<int> &parent)
{
    distVect[S] = 0;
    parent[S] = -1;

    for (int i = 0; i < V - 1; i++)
    {
        for (auto edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            int wt = edge[2];
            if (distVect[from] != INT_MAX && distVect[from] + wt < distVect[to])
            {
                distVect[to] = distVect[from] + wt;
                parent[to] = from;
            }
        }
    }

    return !isNegativeCycle(edges, distVect);
}

int main()
{
    int V, E;
    cout << "Enter Number of Vertices and Edges: ";
    cin >> V >> E;
    vector<vector<int>> edges;
    cout << "Enter Edges and Weights (u v w):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }
    int S;
    cout << "Enter Akshay's House Number: ";
    cin >> S;

    vector<int> distVect(V, INT_MAX);
    vector<int> parent(V, -1);

    if (!bellmanFord(V, edges, S, distVect, parent))
    {
        cout << "Negative weight cycle detected!\n";
        return 0;
    }

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

// Example Input:
// 8 11
// 0 1 3
// 0 3 1
// 0 7 7
// 1 2 6
// 1 3 3
// 3 4 8
// 3 5 1
// 4 2 6
// 4 6 3
// 5 4 2
// 2 7 1
