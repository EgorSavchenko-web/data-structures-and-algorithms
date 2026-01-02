#include <iostream>
#include <vector>

#define pb push_back

using namespace std;

struct DataUnit {
    int num;
    int idx;
    int cnt;
};

void mergeSegments(vector<DataUnit>& arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    DataUnit* left = new DataUnit[len1];
    DataUnit* right = new DataUnit[len2];

    for (int x = 0; x < len1; x++) left[x] = arr[l + x];
    for (int y = 0; y < len2; y++) right[y] = arr[m + 1 + y];

    int a = 0, b = 0, c = l;
    while (a < len1 && b < len2) {
        bool chooseLeft = false;
        if (left[a].cnt != right[b].cnt) {
            chooseLeft = left[a].cnt < right[b].cnt;
        } else if (left[a].num != right[b].num) {
            chooseLeft = left[a].num < right[b].num;
        } else {
            chooseLeft = left[a].idx < right[b].idx;
        }

        if (chooseLeft) {
            arr[c++] = left[a++];
        } else {
            arr[c++] = right[b++];
        }
    }

    while (a < len1) arr[c++] = left[a++];
    while (b < len2) arr[c++] = right[b++];

    delete[] left;
    delete[] right;
}

void segmentedSort(vector<DataUnit>& arr, int beg, int end) {
    if (beg >= end) return;
    int center = beg + (end - beg)/2;
    segmentedSort(arr, beg, center);
    segmentedSort(arr, center + 1, end);
    mergeSegments(arr, beg, center, end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int total;
    cin >> total;
    
    vector<int> vals(total);
    vector<int> tally(1001, 0);
    for (int pos = 0; pos < total; ++pos) {
        cin >> vals[pos];
        tally[vals[pos]]++;
    }

    vector<DataUnit> collection;
    collection.reserve(total);
    for (int pos = 0; pos < total; ++pos) {
        collection.pb({vals[pos], pos, tally[vals[pos]]});
    }

    segmentedSort(collection, 0, collection.size()-1);


    for (auto& item : collection) {
        cout << item.num << " " << item.idx << "\n";
    }

    return 0;
}