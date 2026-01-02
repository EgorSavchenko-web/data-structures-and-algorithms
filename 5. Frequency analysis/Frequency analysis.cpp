#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>

using namespace std;

string Find_Word(int n, int k, const string& s) {
    vector<string> words;
    stringstream ss(s);
    string word;

    while (ss >> word) {
        words.push_back(word);
    }

    vector<array<string, 2>> hash;
    for (const auto& ptr : words) {
        bool found = false;
        for (auto& entry : hash) {
            if (entry[0] == ptr) {
                entry[1] = to_string(stoi(entry[1]) + 1);
                found = true;
                break;
            }
        }
        if (!found) {
            hash.push_back({ptr, "1"});
        }
    }

    vector<string> result;
    while (result.size() < k) {
        int maxCount = -1;
        int pointer = -1;

        for (int y = 0; y < int(hash.size()); y++) {
            if (stoi(hash[y][1]) > maxCount) {
                maxCount = stoi(hash[y][1]);
                pointer = y;
            }
        }

        if (pointer != -1) {
            result.push_back(hash[pointer][0]);
            hash[pointer][1] = "0"; // Mark as checked
        }
    }

    return result[k - 1];
}

int main() {
    int n, k;
    cin >> n >> k;
    cin.ignore();

    string s;
    getline(cin, s);
    
    string result = Find_Word(n, k, s);
    
    cout << result << endl;

    return 0;
}