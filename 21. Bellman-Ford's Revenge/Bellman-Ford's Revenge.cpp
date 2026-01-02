#include <iostream>


using namespace std;

struct Edge {
    int u, v;
    int w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Edge* edges = new Edge[n * n];
    int edge_count = 0;

    int** matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if ((i != j && matrix[i][j] != 0) || (i == j && matrix[i][j] != 0)) {
                edges[edge_count].u = i;
                edges[edge_count].v = j;
                edges[edge_count].w = matrix[i][j];
                edge_count++;
            }
        }
    }

    int* dist = new int[n];
    int* parent = new int[n];
    for (int i = 0; i < n; i++) {
        dist[i] = 0;
        parent[i] = -1;
    }

    int x = -1;
    for (int i = 0; i < n; i++) {
        x = -1;
        for (int j = 0; j < edge_count; j++) {
            Edge edge = edges[j];
            if (dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
                parent[edge.v] = edge.u;
                x = edge.v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    int cycleStart = x;
    for (int i = 0; i < n; i++) {
        cycleStart = parent[cycleStart];
    }

    int* cycle = new int[n + 1];
    int cycle_size = 0;
    int current = cycleStart;
    do {
        cycle[cycle_size++] = current;
        if (current == cycleStart && cycle_size > 1) {
            break;
        }
        current = parent[current];
    } while (true);

    for (int i = 0; i < cycle_size / 2; i++) {
        int temp = cycle[i];
        cycle[i] = cycle[cycle_size - 1 - i];
        cycle[cycle_size - 1 - i] = temp;
    }

    cout << "YES\n" << cycle_size - 1 << "\n";
    for (int i = 0; i < cycle_size - 1; i++) {
        cout << cycle[i] + 1 << " ";
    }
    cout << "\n";

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] edges;
    delete[] dist;
    delete[] parent;
    delete[] cycle;

    return 0;
}