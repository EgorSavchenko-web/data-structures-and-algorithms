#include <iostream>
#include <vector>

using namespace std;

int k_ary_search(const vector<int>& arr, int target, int k, int left, int right) {
    int step = (right - left) / k;
    vector<int> midpoints(k);
    
    if (left > right) {
        return -1;
    }
    if (left == right) {
        return (arr[left] == target) ? left : -1;
    }
    
    for (int i = 0; i < k; ++i) {
        midpoints[i] = left + i * step;
        if (i == k - 1) {
            midpoints[i] = right;
        }
    }
    for (int i = 0; i < k; ++i) {
        if (arr[midpoints[i]] == target) {
            return midpoints[i];
        }
    }

    if (target < arr[midpoints[0]]) {
        return k_ary_search(arr, target, k, left, midpoints[0] - 1);
    }
    if (target > arr[midpoints[k - 1]]) {
        return k_ary_search(arr, target, k, midpoints[k - 1] + 1, right);
    }

    for (int i = 0; i < k - 1; ++i) {
        if (target >= arr[midpoints[i]] && target < arr[midpoints[i + 1]]) {
            return k_ary_search(arr, target, k, midpoints[i] + 1, midpoints[i + 1] - 1);
        }
    }

    return -1;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> arr(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int M;
    cin >> M;

    while (M--) {
        int target;
        cin >> target;
        cout << k_ary_search(arr, target, K, 0, N - 1) << endl;
    }

    return 0;
}