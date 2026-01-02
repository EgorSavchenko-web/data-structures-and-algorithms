#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Learner {
    int grade;
    string fullName;
};

void swap(Learner& a, Learner& b) {
    Learner temp = a;
    a = b;
    b = temp;
}

bool compareByGrade(const Learner& a, const Learner& b) {
    return a.grade < b.grade;
}

int partition(vector<Learner>& learners, int low, int high) {
    Learner pivot = learners[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (compareByGrade(learners[j], pivot)) {
            i++;
            swap(learners[i], learners[j]);
        }
    }
    swap(learners[i + 1], learners[high]);
    return i + 1;
}

void quicksort(vector<Learner>& learners, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(learners, low, high);
        quicksort(learners, low, pivotIndex - 1);
        quicksort(learners, pivotIndex + 1, high);
    }
}

int main() {
    int count;
    cin >> count;
    
    vector<Learner> learners(count);
    
    for (int index = 0; index < count; ++index) {
        cin >> learners[index].grade;
        cin.ignore();
        getline(cin, learners[index].fullName);
    }
    
    quicksort(learners, 0, count - 1);
    
    cout << learners[count / 2].fullName << endl;
    
    return 0;
}