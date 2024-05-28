#include <iostream>
#include <vector>
using namespace std;
void checkPathUsingDFS(int src, vector<int> &visited, vector<int> adj[])
{
    visited[src] = 1;
    for (auto it : adj[src])
    {
        if (!visited[it])
        {
            checkPathUsingDFS(it, visited, adj);
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter number of vertices : ";
    cin >> n;
    cout << "Enter number of edges : ";
    cin >> e;
    vector<int> adj[n];
    int u, v;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter u and v :";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int src, dest;
    cout << "Enter source :";
    cin >> src;
    cout << "Enter destination : ";
    cin >> dest;
    vector<int> visited(n, 0);
    checkPathUsingDFS(src, visited, adj);
    if (visited[dest] == 1)
    {
        cout << "Yes Path exists!" << endl;
    }
    else
    {
        cout << "No Path Exists!!" << endl;
    }
}