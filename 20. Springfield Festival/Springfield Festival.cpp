#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Edge {
    int to;
    double weight;
};

struct HeapElement {
    double weight;
    int from;
    int to;
    HeapElement(double w, int f, int t) : weight(w), from(f), to(t) {}
};

void pushHeap(vector<HeapElement>& heap, const HeapElement& e) {
    heap.push_back(e);
    int index = heap.size() - 1;
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index].weight < heap[parent].weight) {
            HeapElement temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            index = parent;
        } else {
            break;
        }
    }
}

HeapElement popHeap(vector<HeapElement>& heap) {
    HeapElement top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    int index = 0;
    int n = heap.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < n && heap[left].weight < heap[smallest].weight) {
            smallest = left;
        }
        if (right < n && heap[right].weight < heap[smallest].weight) {
            smallest = right;
        }
        if (smallest != index) {
            HeapElement temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;
            index = smallest;
        } else {
            break;
        }
    }
    return top;
}

int main() {
    int N;
    cin >> N;

    vector<string> names;
    vector<double> tax;
    vector<vector<Edge>> graph;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string stallName;
            double taxValue;
            cin >> stallName >> taxValue;
            names.push_back(stallName);
            tax.push_back(taxValue);
            graph.push_back(vector<Edge>());
        } else if (cmd == "CONNECT") {
            string s1, s2;
            double distance;
            cin >> s1 >> s2 >> distance;

            int id1 = -1, id2 = -1;
            for (int j = 0; j < names.size(); ++j) {
                if (names[j] == s1) id1 = j;
                if (names[j] == s2) id2 = j;
            }

            double weight = distance / (tax[id1] + tax[id2]);
            graph[id1].push_back({id2, weight});
            graph[id2].push_back({id1, weight});
        } else if (cmd == "PRINT_MIN") {
            int n = names.size();
            vector<bool> inMST(n, false);
            vector<int> parent(n, -1);
            vector<pair<int, int>> mstEdges;

            for (int start = 0; start < n; start++) {
                if (inMST[start]) continue;

                vector<HeapElement> heap;
                inMST[start] = true;

                for (auto &edge : graph[start]) {
                    pushHeap(heap, HeapElement(edge.weight, start, edge.to));
                }

                while (!heap.empty()) {
                    HeapElement e = popHeap(heap);
                    double w = e.weight;
                    int from = e.from;
                    int to = e.to;

                    if (inMST[to]) continue;
                    inMST[to] = true;
                    parent[to] = from;
                    mstEdges.push_back({from, to});

                    for (auto &edge : graph[to]) {
                        if (!inMST[edge.to]) {
                            pushHeap(heap, HeapElement(edge.weight, to, edge.to));
                        }
                    }
                }
            }

            for (auto &edge : mstEdges) {
                cout << names[edge.first] << ":" << names[edge.second] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}