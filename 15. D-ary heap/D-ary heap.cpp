#include <iostream>
#include <vector>
using namespace std;

vector<int> combineVectors(const vector<int>& first, const vector<int>& second) {
    vector<int> result;
    int i = 0;
    int j = 0;

    while (i < first.size() && j < second.size()) {
        if (first[i] >= second[j]) {
            result.push_back(first[i]);
            i = i + 1;
        } else {
            result.push_back(second[j]);
            j = j + 1;
        }
    }

    while (i < first.size()) {
        result.push_back(first[i]);
        i = i + 1;
    }

    while (j < second.size()) {
        result.push_back(second[j]);
        j = j + 1;
    }

    return result;
}

void sortArray(vector<int>& numbers) {
    if (numbers.size() <= 1) {
        return;
    }

    int middle = numbers.size() / 2;

    vector<int> leftPart(numbers.begin(), numbers.begin() + middle);
    vector<int> rightPart(numbers.begin() + middle, numbers.end());

    sortArray(leftPart);
    sortArray(rightPart);

    numbers = combineVectors(leftPart, rightPart);
}

int main() {
    int d, howMany;
    cin >> howMany >> d;

    vector<int> myArray(howMany);
    for (int i = 0; i < howMany; i++) {
        cin >> myArray[i];
    }

    sortArray(myArray);

    for (int i = 0; i < howMany; i++) {
        cout << myArray[i];
        if (i < howMany - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}