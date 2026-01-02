#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Vec2 {
    double a, b;
};

double getLength(const Vec2& v) {
    return sqrt(v.a*v.a + v.b*v.b);
}

void joinSections(vector<Vec2>& arr, int low, int pivot, int high) {
    int left_len = pivot - low + 1;
    int right_len = high - pivot;
    
    Vec2* left = new Vec2[left_len];
    Vec2* right = new Vec2[right_len];
    
    for(int idx = 0; idx < left_len; idx++)
        left[idx] = arr[low + idx];
    for(int idx = 0; idx < right_len; idx++)
        right[idx] = arr[pivot + 1 + idx];
    
    int i = 0, j = 0, pos = low;
    while(i < left_len && j < right_len) {
        bool leftFirst = getLength(left[i]) <= getLength(right[j]);
        arr[pos++] = leftFirst ? left[i++] : right[j++];
    }
    
    while(i < left_len) arr[pos++] = left[i++];
    while(j < right_len) arr[pos++] = right[j++];
    
    delete[] left;
    delete[] right;
}

void recursiveSort(vector<Vec2>& arr, int start, int end) {
    if(start >= end) return;
    int mid = start + ((end - start) >> 1);
    recursiveSort(arr, start, mid);
    recursiveSort(arr, mid + 1, end);
    joinSections(arr, start, mid, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<Vec2> points(n);
    for(int i = 0; i < n; i++) {
        cin >> points[i].a >> points[i].b;
    }
    
    recursiveSort(points, 0, n-1);
    
    for(const auto& p : points) {
        printf("%.4f %.4f\n", p.a, p.b);
    }
    
    return 0;
}