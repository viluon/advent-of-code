#define PART2
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifdef PART2
int get_rating(bool prefer1, const vector<vector<int>>& ns) {
    int i = 0;
    int res = 0;
    vector<vector<int>> considered = ns;
    int preferred = prefer1 ? 1 : 0;
    while (considered.size() > 1 && i < considered[0].size()) {
        auto count = make_pair(0, 0);
        for (auto n : considered) {
            if (n[i] == 1) { count.first++; }
            else { count.second++; }
        }
        auto next = considered;
        for (int j = considered.size() - 1; j >= 0; j--) {
            if (considered[j][i] == count.first >= count.second ? 1 - preferred : preferred) {
                next.erase(next.begin() + j);
            }
        }
        considered = next;
        i++;
    }
    for (auto n : considered[0]) {
        res = res * 2 + n;
    }
    return res;
}
#endif

int main() {
    #ifndef PART2
    vector<pair<int, int>> ns;
    string n;
    while (cin >> n) {
        int i = 0;
        for (char ch : n) {
            if (i >= ns.size()) {
                ns.push_back({0, 0});
            }

            if (ch == '1') {
                ns[i].first++;
            } else {
                ns[i].second++;
            }
            i++;
        }
    }

    int gamma = 0, epsilon = 0;
    for (auto p : ns) {
        if (p.first > p.second) {
            gamma = gamma * 2 + 1;
            epsilon *= 2;
        } else {
            gamma *= 2;
            epsilon = epsilon * 2 + 1;
        }
    }

    cout << gamma * epsilon << endl;
    #else
    vector<vector<int>> ns;
    string str;
    while (cin >> str) {
        vector<int> n;
        for (char ch : str) {
            n.push_back(ch - '0');
        }
        ns.push_back(n);
    }

    cout << get_rating(true, ns) * get_rating(false, ns) << endl;
    #endif

    return 0;
}
