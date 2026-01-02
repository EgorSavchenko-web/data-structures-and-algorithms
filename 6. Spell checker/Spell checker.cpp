#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
void Find_Words(int &k, vector<string>& result) {
    int number1;
    cin >> number1;
    cin.ignore();
    string S1;
    getline(cin, S1);
    int number2;
    cin >> number2;
    cin.ignore();
    string S2;
    getline(cin, S2);
    vector<string> words2;
    string word;
    stringstream ss2(S2);
    while (ss2 >> word) {
        words2.push_back(word);
    }
    result.clear();
    stringstream ss1(S1);
    while (ss1 >> word) {
        bool inS2 = false;
        for (size_t i = 0; i < words2.size(); i++) {
            if (words2[i] == word) {
                inS2 = true;
                break;
            }
        }
        if (!inS2) {
            bool alreadyAdded = false;
            for (size_t i = 0; i < result.size(); i++) {
                if (result[i] == word) {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded)
                result.push_back(word);
        }
    }
    k = result.size();
}
int main() {
    int k;
    vector<string> result;
    Find_Words(k, result);
    cout << k << "\n";
    for (size_t i = 0; i < result.size(); i++)
        cout << result[i] << "\n";
    return 0;
}