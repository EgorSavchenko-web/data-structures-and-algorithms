#include <iostream>

using namespace std;

const long long INF = 1000000000000000000LL;


struct Edge {
    int to;
    long long distance;
    long long bandwidth;
    Edge* next;
};

struct Node {
    int vertex;
    long long distance;
    long long bandwidth;

    bool operator>(const Node& other) const {
        if (distance == other.distance) {
            return bandwidth < other.bandwidth;
        }
        return distance > other.distance;
    }
};

void insert_node(Node*& heap, int& heap_size, int& heap_capacity, const Node& node) {
    if (heap_size == heap_capacity) {
        int new_capacity = heap_capacity * 2;
        Node* new_heap = new Node[new_capacity];
        for (int i = 0; i < heap_size; ++i) {
            new_heap[i] = heap[i];
        }
        delete[] heap;
        heap = new_heap;
        heap_capacity = new_capacity;
    }
    heap[heap_size] = node;
    heap_size++;
    int current = heap_size - 1;
    while (current > 0) {
        int parent = (current - 1) / 2;
        if (heap[parent] > heap[current]) {
            Node temp = heap[parent];
            heap[parent] = heap[current];
            heap[current] = temp;
            current = parent;
        } else {
            break;
        }
    }
}

Node extract_min(Node*& heap, int& heap_size) {
    Node min_node = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    int current = 0;
    while (true) {
        int left = 2 * current + 1;
        int right = 2 * current + 2;
        int smallest = current;
        if (left < heap_size && heap[smallest] > heap[left]) {
            smallest = left;
        }
        if (right < heap_size && heap[smallest] > heap[right]) {
            smallest = right;
        }
        if (smallest != current) {
            Node temp = heap[current];
            heap[current] = heap[smallest];
            heap[smallest] = temp;
            current = smallest;
        } else {
            break;
        }
    }
    return min_node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    Edge** graph = new Edge*[n + 1]();

    for (int i = 0; i < m; ++i) {
        int u, v;
        long long d, b;
        cin >> u >> v >> d >> b;
        Edge* edge1 = new Edge;
        edge1->to = v;
        edge1->distance = d;
        edge1->bandwidth = b;
        edge1->next = graph[u];
        graph[u] = edge1;

        Edge* edge2 = new Edge;
        edge2->to = u;
        edge2->distance = d;
        edge2->bandwidth = b;
        edge2->next = graph[v];
        graph[v] = edge2;
    }

    int s, t;
    cin >> s >> t;

    if (n == 1 && m == 0 && s == t) {
        cout << "0 0" << endl;
        for (int i = 0; i <= n; ++i) {
            Edge* current = graph[i];
            while (current != nullptr) {
                Edge* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] graph;
        return 0;
    }

    long long* dist = new long long[n + 1];
    long long* max_bandwidth = new long long[n + 1];
    for (int i = 0; i <= n; ++i) {
        dist[i] = INF;
        max_bandwidth[i] = 0;
    }
    dist[s] = 0;
    max_bandwidth[s] = INF;

    int heap_capacity = 1;
    int heap_size = 0;
    Node* heap = new Node[heap_capacity];
    Node start_node;
    start_node.vertex = s;
    start_node.distance = 0;
    start_node.bandwidth = INF;
    insert_node(heap, heap_size, heap_capacity, start_node);

    while (heap_size > 0) {
        Node current = extract_min(heap, heap_size);
        int u = current.vertex;
        long long current_distance = current.distance;
        long long current_bandwidth = current.bandwidth;

        if (current_distance > dist[u] || (current_distance == dist[u] && current_bandwidth < max_bandwidth[u])) {
            continue;
        }

        Edge* edge_ptr = graph[u];
        while (edge_ptr != nullptr) {
            int v = edge_ptr->to;
            long long new_distance = current_distance + edge_ptr->distance;
            long long new_bandwidth = current_bandwidth < edge_ptr->bandwidth ? current_bandwidth : edge_ptr->bandwidth;

            if (new_distance < dist[v] || (new_distance == dist[v] && new_bandwidth > max_bandwidth[v])) {
                dist[v] = new_distance;
                max_bandwidth[v] = new_bandwidth;
                Node new_node;
                new_node.vertex = v;
                new_node.distance = new_distance;
                new_node.bandwidth = new_bandwidth;
                insert_node(heap, heap_size, heap_capacity, new_node);
            }
            edge_ptr = edge_ptr->next;
        }
    }

    if (dist[t] == INF) {
        cout << "-1 -1" << endl;
    } else {
        cout << dist[t] << " " << (max_bandwidth[t] == INF ? 0 : max_bandwidth[t]) << endl;
    }

    for (int i = 0; i <= n; ++i) {
        Edge* current = graph[i];
        while (current != nullptr) {
            Edge* next = current->next;
            delete current;
            current = next;
        }
    }
    delete[] graph;
    delete[] dist;
    delete[] max_bandwidth;
    delete[] heap;

    return 0;
}