#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000000;

int myMin(int a, int b) {
    return (a < b) ? a : b;
}

struct Arc {
    int dest;
    int capacity;
    int flow;
    int revIndex;
};

class MyQueue {
public:
    MyQueue(int maxSize) {
        data.resize(maxSize);
        head = 0;
        tail = 0;
    }

    void push(pair<int, int> value) {
        data[tail++] = value;
    }

    pair<int, int> front() {
        return data[head];
    }

    void pop() {
        head++;
    }

    bool empty() {
        return head == tail;
    }

    void clear() {
        head = tail = 0;
    }

private:
    vector<pair<int, int>> data;
    int head, tail;
};

class MaxFlowCalculator {
public:
    MaxFlowCalculator(int vertices) : numVertices(vertices) {
        network.resize(vertices + 1);
    }

    void addConnection(int from, int to, int cap) {
        Arc forward = {to, cap, 0, (int)network[to].size()};
        Arc reverse = {from, 0, 0, (int)network[from].size()};
        network[from].push_back(forward);
        network[to].push_back(reverse);
    }

    int calculateFlow(int source, int sink) {
        int maxFlow = 0;
        vector<int> predecessor(numVertices + 1);

        while (true) {
            int pathFlow = findPath(source, sink, predecessor);
            if (pathFlow == 0)
                break;
            maxFlow += pathFlow;

            int cur = sink;
            while (cur != source) {
                int prev = predecessor[cur];

                for (int i = 0; i < (int)network[prev].size(); i++) {
                    if (network[prev][i].dest == cur) {
                        network[prev][i].flow += pathFlow;
                        break;
                    }
                }

                for (int i = 0; i < (int)network[cur].size(); i++) {
                    if (network[cur][i].dest == prev) {
                        network[cur][i].flow -= pathFlow;
                        break;
                    }
                }

                cur = prev;
            }
        }

        return maxFlow;
    }

private:
    int numVertices;
    vector<vector<Arc>> network;

    void fillVector(vector<int> &vec, int val) {
        for (int i = 0; i < (int)vec.size(); i++) {
            vec[i] = val;
        }
    }

    int findPath(int start, int sink, vector<int> &prev) {
        fillVector(prev, -1);
        prev[start] = -2;

        MyQueue q(numVertices * 10);
        q.push({start, INF});

        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();

            int cur = front.first;
            int flow = front.second;

            for (int i = 0; i < (int)network[cur].size(); i++) {
                Arc &edge = network[cur][i];
                if (prev[edge.dest] == -1 && edge.flow < edge.capacity) {
                    prev[edge.dest] = cur;
                    int newFlow = myMin(flow, edge.capacity - edge.flow);
                    if (edge.dest == sink) {
                        return newFlow;
                    }
                    q.push({edge.dest, newFlow});
                }
            }
        }

        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;

    MaxFlowCalculator solver(vertexCount);

    for (int i = 0; i < edgeCount; i++) {
        int u, v, cap;
        cin >> u >> v >> cap;
        solver.addConnection(u, v, cap);
    }

    cout << solver.calculateFlow(1, vertexCount) << "\n";

    return 0;
}