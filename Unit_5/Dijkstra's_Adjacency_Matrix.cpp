// 4) Write a Program to implement Dijkstra’s algorithm to find shortest distance
//  between two nodes of a user defined graph. Use Adjacency Matrix to represent a
//  graph.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int findMinvertex(vector<int> &dist, vector<bool> &visited, int n)
{
    int minvertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minvertex == -1 || dist[i] < dist[minvertex]))
        {
            minvertex = i;
        }
    }
    return minvertex;
}
void dijkstras(vector<vector<int>> &graph, int src, int n)
{

    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int i = 0; i < n; i++)
    {
        int u = findMinvertex(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] && !visited[v] && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    cout << "Shortest distance from vertex " << src << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << src << " -> " << i << " = " << dist[i] << endl;
    }
}
int main()
{

    // vector<vector<int>> adj{
    //     {0, 1, 1, 1, 0, 0, 0},
    //     {1, 0, 1, 0, 0, 0, 0},
    //     {1, 1, 0, 1, 1, 0, 0},
    //     {1, 0, 1, 0, 1, 0, 0},
    //     {0, 0, 1, 1, 0, 1, 1},
    //     {0, 0, 0, 0, 1, 0, 0},
    //     {0, 0, 0, 0, 1, 0, 0}};
    // int n = 7;
    int n;
    cout << "Enter number of vertices in matrix : ";
    cin >> n;

    vector<vector<int>> adj(n, vector<int>(n));

    cout << "Enter adjacecny matrix " << n << "x" << n << " : " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    dijkstras(adj, 0, 5);
}