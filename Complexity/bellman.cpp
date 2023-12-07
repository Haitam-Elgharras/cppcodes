#include <iostream>
#include <climits>

using namespace std;

const int V = 6; // Number of vertices

void bellmanFord(int graph[V][V], int source)
{
    int distance[V];

    // Initialize distances
    for (int i = 0; i < V; i++)
    {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    // Relax edges repeatedly
    bool relaxed = false;
    for (int i = 0; i < V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                // the main condition is distance[v] > distance[u] + graph[u][v]
                // the final condition distance[v] > distance[u] + graph[u][v] technically includes the other conditions
                // but we need to check for INT_MAX to avoid overflow
                if (graph[u][v] != INT_MAX && distance[u] != INT_MAX && distance[v] > distance[u] + graph[u][v])
                {
                    distance[v] = distance[u] + graph[u][v];
                    relaxed = true;
                }
            }
        }
        if (!relaxed)
        {
            // we reach a stable version of the distances
            cout << "No more relaxations possible!" << endl;
            break;
        }
    }

    // // Check for negative cycles
    for (int u = 0; u < V; u++)
    {
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != INT_MAX && distance[u] != INT_MAX && distance[v] > distance[u] + graph[u][v])
            {
                // after V-1 iterations, the distances are stable if it's not the case, then there is a negative cycle
                cout << "Graph contains negative cycle!" << endl;
                return;
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances from source " << char('A' + source) << " to all other vertices:" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << char('A' + i) << ": " << distance[i] << endl;
    }
}

int main()
{
    int graph[V][V] = {
        {0, 2, INT_MAX, 6, 5, INT_MAX},
        {INT_MAX, 0, 1, INT_MAX, INT_MAX, INT_MAX},
        {INT_MAX, INT_MAX, 0, INT_MAX, 1, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 6},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 1},
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX}};

    int source = 0; // Source vertex (A=0)
    bellmanFord(graph, source);

    return 0;
}
