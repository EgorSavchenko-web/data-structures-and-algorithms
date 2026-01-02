#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    bool present[26];
    for (int i = 0; i < 26; i++) present[i] = false;
    int num_present = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < words[i].size(); j++) {
            int idx = words[i][j] - 'a';
            if (!present[idx]) {
                present[idx] = true;
                num_present++;
            }
        }
    }

    int adj[26][26];
    int adj_size[26];
    bool edge[26][26];
    for (int i = 0; i < 26; i++) {
        adj_size[i] = 0;
        for (int j = 0; j < 26; j++) {
            edge[i][j] = false;
        }
    }
    bool impossible = false;
    for (int i = 0; i < N - 1; i++) {
        const string& w1 = words[i];
        const string& w2 = words[i + 1];
        int min_len = w1.size();
        if (w2.size() < min_len) min_len = w2.size();
        bool differ = false;
        for (int j = 0; j < min_len; j++) {
            if (w1[j] != w2[j]) {
                int a = w1[j] - 'a';
                int b = w2[j] - 'a';
                if (!edge[a][b]) {
                    adj[a][adj_size[a]] = b;
                    adj_size[a]++;
                    edge[a][b] = true;
                }
                differ = true;
                break;
            }
        }
        if (!differ && w1.size() > w2.size()) {
            impossible = true;
            break;
        }
    }

    if (impossible) {
        cout << "Doh" << endl;
        return 0;
    }

    int indegree[26];
    for (int i = 0; i < 26; i++) indegree[i] = 0;
    for (int u = 0; u < 26; u++) {
        if (present[u]) {
            for (int j = 0; j < adj_size[u]; j++) {
                int v = adj[u][j];
                indegree[v]++;
            }
        }
    }

    int stack[26];
    int top = -1;
    string order = "";
    int count = 0;
    for (int u = 0; u < 26; u++) {
        if (present[u] && indegree[u] == 0) {
            stack[++top] = u;
        }
    }
    while (top >= 0) {
        int u = stack[top--];
        order += (char)('a' + u);
        count++;
        for (int j = 0; j < adj_size[u]; j++) {
            int v = adj[u][j];
            indegree[v]--;
            if (indegree[v] == 0) {
                stack[++top] = v;
            }
        }
    }

    if (count == num_present) {
        cout << order << endl;
    } else {
        cout << "Doh" << endl;
    }

    return 0;
}