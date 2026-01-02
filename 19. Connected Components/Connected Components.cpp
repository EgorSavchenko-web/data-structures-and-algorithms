#include <iostream>

void init(int* parent, int* size, int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

int find(int x, int* parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);
    }
    return parent[x];
}

void unite(int x, int y, int* parent, int* size) {
    x = find(x, parent);
    y = find(y, parent);
    if (x != y) {
        if (size[x] < size[y]) {
            int temp = x;
            x = y;
            y = temp;
        }
        parent[y] = x;
        size[x] += size[y];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    int* parent = new int[n + 1];
    int* size = new int[n + 1];
    init(parent, size, n);

    int components = n;

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;

        int root_u = find(u, parent);
        int root_v = find(v, parent);

        if (root_u != root_v) {
            unite(u, v, parent, size);
            components--;
        }
    }

    std::cout << components << '\n';

    delete[] parent;
    delete[] size;

    return 0;
}