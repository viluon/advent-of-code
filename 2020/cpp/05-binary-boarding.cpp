#define PART2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    using namespace std;

    string boarding_pass;
    vector<int> ids;
    while (cin >> boarding_pass) {
        int lo = 0, hi = 128;
        int c_lo = 0, c_hi = 8;
        for (char ch : boarding_pass) {
            switch (ch) {
                case 'F':
                    hi -= (hi - lo) / 2;
                    break;
                case 'B':
                    lo += (hi - lo) / 2;
                    break;
                case 'L':
                    c_hi -= (c_hi - c_lo) / 2;
                    break;
                case 'R':
                    c_lo += (c_hi - c_lo) / 2;
                    break;
            }
        }

        ids.push_back(lo * 8 + c_lo);
    }

    sort(ids.begin(), ids.end());
    #ifndef PART2
    cout << ids[ids.size() - 1] << endl;

    return 0;
    #else
    auto f = [&](int i) { return find(ids.begin(), ids.end(), i) != ids.end(); };
    for (int n = 0; n <= ids[ids.size() - 1]; n++) {
        if (!f(n) && f(n - 1) && f(n + 1)) {
            cout << n << endl;
            return 0;
        }
    }

    return 1;
    #endif
}
