#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int node_count, edge_count;
    cin >> node_count >> edge_count;

    vector<vector<pair<int, ll>>> graph(node_count + 1);

    for (int i = 0; i < edge_count; ++i) {
        int start, end, capacity, flow;
        cin >> start >> end >> capacity >> flow;

        ll residual_capacity = capacity - flow;
        if (residual_capacity > 0) {
            graph[start].push_back({end, residual_capacity});
        }

        if (flow > 0) {
            graph[end].push_back({start, flow});
        }
    }

    vector<int> previous(node_count + 1, -1);
    vector<ll> min_capacity(node_count + 1, 0);
    vector<bool> explored(node_count + 1, false);

    vector<pair<int, ll>> exploration_queue;
    explored[1] = true;
    exploration_queue.push_back({1, INF});

    bool path_found = false;

    int front = 0;
    while (front < exploration_queue.size()) {
        auto [current_node, current_capacity] = exploration_queue[front++];
        
        if (current_node == node_count) {
            path_found = true;
            break;
        }

        for (auto& neighbor : graph[current_node]) {
            int next_node = neighbor.first;
            ll edge_capacity = neighbor.second;

            if (!explored[next_node]) {
                explored[next_node] = true;
                ll new_capacity = min(current_capacity, edge_capacity);
                previous[next_node] = current_node;
                min_capacity[next_node] = new_capacity;
                exploration_queue.push_back({next_node, new_capacity});
            }
        }
    }

    if (!path_found) {
        cout << "NO PATH\n";
    } else {
        vector<int> final_path;
        int current_node = node_count;
        while (current_node != -1) {
            final_path.push_back(current_node);
            current_node = previous[current_node];
        }

        int path_length = final_path.size();
        ll min_residual = min_capacity[node_count];
        cout << path_length << " " << min_residual << "\n";

        for (int i = path_length - 1; i >= 0; --i) {
            cout << final_path[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}