#include <iostream>

struct Frequency {
    int value;
    int occurrences;
};

int main() {
    int size;
    std::cin >> size;

    int inputArray[100005];
    for (int index = 0; index < size; index++) {
        std::cin >> inputArray[index];
    }

    int frequencyCounts[1005] = {0};

    for (int index = 0; index < size; index++) {
        frequencyCounts[inputArray[index]]++;
    }

    int maxFrequency = 0;
    for (int index = 0; index <= 1000; index++) {
        if (frequencyCounts[index] > maxFrequency) {
            maxFrequency = frequencyCounts[index];
        }
    }

    Frequency resultArray[1005];
    int resultSize = 0;

    for (int index = 0; index <= 1000; index++) {
        if (frequencyCounts[index] > 0) {
            resultArray[resultSize].value = index;
            resultArray[resultSize].occurrences = frequencyCounts[index];
            resultSize++;
        }
    }

    for (int i = 0; i < resultSize - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < resultSize - i - 1; j++) {
            if (resultArray[j].occurrences > resultArray[j + 1].occurrences) {
                Frequency temp = resultArray[j];
                resultArray[j] = resultArray[j + 1];
                resultArray[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    for (int index = 0; index < resultSize; index++) {
        std::cout << resultArray[index].value << "\n";
    }

    return 0;
}