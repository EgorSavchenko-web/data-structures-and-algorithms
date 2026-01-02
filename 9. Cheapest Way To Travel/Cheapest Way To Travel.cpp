#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    vector<vector<int>> mat(rows, vector<int>(cols, 0));
    vector<vector<int>> best(rows, vector<int>(cols, 0));
    vector<vector<pair<int, int>>> prevPos(rows, vector<pair<int, int>>(cols, make_pair(0, 0)));

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            cin >> mat[r][c];
        }
    }
    
    best[0][0] = mat[0][0];

    for (int c = 1; c < cols; c++) {
        best[0][c] = best[0][c - 1] + mat[0][c];
        prevPos[0][c] = make_pair(0, c - 1);
    }
    
    for (int r = 1; r < rows; r++) {
        best[r][0] = best[r - 1][0] + mat[r][0];
        prevPos[r][0] = make_pair(r - 1, 0);
    }
    
    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            int fromTop = best[r - 1][c];
            int fromLeft = best[r][c - 1];
            if (fromTop < fromLeft) {
                best[r][c] = fromTop + mat[r][c];
                prevPos[r][c] = make_pair(r - 1, c);
            } else {
                best[r][c] = fromLeft + mat[r][c];
                prevPos[r][c] = make_pair(r, c - 1);
            }
        }
    }
    
    vector<int> sequence;
    int currR = rows - 1, currC = cols - 1;
    while (currR != 0 || currC != 0) {
        sequence.push_back(mat[currR][currC]);
        int newRow = prevPos[currR][currC].first;
        int newCol = prevPos[currR][currC].second;
        currR = newRow;
        currC = newCol;
    }
    sequence.push_back(mat[0][0]);

    cout << best[rows - 1][cols - 1] << "\n";
    for (int k = sequence.size() - 1; k >= 0; k--) {
        cout << sequence[k] << " ";
    }
    cout << "\n";

    return 0;
}