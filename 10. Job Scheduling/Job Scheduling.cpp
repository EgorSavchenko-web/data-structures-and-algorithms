#include <iostream>
#include <vector>

using namespace std;

struct Data {
    int start;
    int finish;
    int weight;
};

void swap(Data& a, Data& b) {
    Data temp = a;
    a = b;
    b = temp;
}

//QuickSort implementation was adopted from https://www.programiz.com/dsa/quick-sort

int partition(vector<Data>& items, int low, int high) {
    Data pivot = items[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (items[j].finish < pivot.finish) {
            i++;
            swap(items[i], items[j]);
        }
    }

    swap(items[i + 1], items[high]);
    return i + 1;
}

void quickSort(vector<Data>& items, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(items, low, high);
        quickSort(items, low, pivotIndex - 1);
        quickSort(items, pivotIndex + 1, high);
    }
}

int findPreviousItem(const vector<Data>& items, int current) {
    for (int i = current - 1; i >= 0; --i) {
        if (items[i].finish <= items[current].start) {
            return i;
        }
    }
    return -1;
}

int processItems(vector<Data>& items) {
    int count = items.size();
    quickSort(items, 0, count - 1);

    vector<int> dp(count);
    dp[0] = items[0].weight;

    for (int i = 1; i < count; ++i) {
        int currentTotal = items[i].weight;
        int previousItem = findPreviousItem(items, i);
        if (previousItem != -1) {
            currentTotal += dp[previousItem];
        }
        dp[i] = max(currentTotal, dp[i - 1]);
    }

    return dp[count - 1];
}

int main() {
    int count;
    cin >> count;

    vector<Data> items(count);
    for (int i = 0; i < count; ++i) {
        cin >> items[i].start;
    }
    for (int i = 0; i < count; ++i) {
        cin >> items[i].finish;
    }
    for (int i = 0; i < count; ++i) {
        cin >> items[i].weight;
    }

    cout << processItems(items) << endl;

    return 0;
}