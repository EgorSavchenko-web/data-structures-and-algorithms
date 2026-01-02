#include <iostream>

using namespace std;

int main() {
    int blocks_total, starting_points_count;
    cin >> blocks_total >> starting_points_count;

    int pointers[100005];
    for (int idx = 0; idx < blocks_total; idx++) {
        cin >> pointers[idx];
    }

    int origins[100005];
    for (int idx = 0; idx < starting_points_count; idx++) {
        cin >> origins[idx];
    }

    bool accessible[100005] = {false};

    for (int pos = 0; pos < starting_points_count; pos++) {
        int base = origins[pos];
        if (!accessible[base]) {
            int current_pos = base;
            while (current_pos >= 0 && current_pos < blocks_total && !accessible[current_pos]) {
                accessible[current_pos] = true;
                current_pos = pointers[current_pos];
            }
        }
    }

    int free_starts[100005], free_lengths[100005];
    int free_count = 0;
    int scan = 0;

    while (scan < blocks_total) {
        if (!accessible[scan]) {
            int begin = scan;
            int length = 0;
            while (scan < blocks_total && !accessible[scan]) {
                length++;
                scan++;
            }
            free_starts[free_count] = begin;
            free_lengths[free_count] = length;
            free_count++;
        } else {
            scan++;
        }
    }

    cout << free_count << endl;
    for (int output_idx = 0; output_idx < free_count; output_idx++) {
        cout << free_starts[output_idx] << " " << free_lengths[output_idx] << endl;
    }

    return 0;
}