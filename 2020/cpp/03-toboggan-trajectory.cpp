#include <iostream>
#include <string>
#include <vector>

#define PART2

int main() {
    using namespace std;
    vector<vector<bool>> grid;

    for (string row; cin >> row;) {
        vector<bool> row_bools;
        for (char c : row) {
            row_bools.push_back(c == '#');
        }
        grid.push_back(row_bools);
    }

    // count encountered trees
    #ifndef PART2
    int trees = 0;
    size_t x = 0;
    for (auto row : grid) {
        if (row[x]) {
            trees++;
        }
        x = (x + 3) % row.size();
    }
    #else
    vector<pair<int, int>> slopes = {
        {1, 1},
        {3, 1},
        {5, 1},
        {7, 1},
        {1, 2}
    };

    long trees = 1;
    for (auto slope : slopes) {
        int trees_on_slope = 0;
        size_t x = 0, y = 0;

        while (y < grid.size()) {
            if (grid[y][x]) {
                trees_on_slope++;
            }
            x += slope.first;
            x %= grid[y].size();
            y += slope.second;
        }

        trees *= trees_on_slope;
    }

    #endif

    cout << trees << endl;

    return 0;
}
