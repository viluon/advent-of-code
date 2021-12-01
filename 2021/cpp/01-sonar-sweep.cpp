#define PART2
#include <iostream>

int main() {
    using namespace std;
    int n;
    int prev;
    int increased = 0;
    #ifdef PART2
    int prevprev;
    cin >> prevprev;
    int last = 0xffffff;
    #endif
    cin >> prev;
    while (cin >> n) {
        #ifndef PART2
        if (n > prev) {
            increased++;
        }
        #else
        int current = n + prev + prevprev;
        if (current > last) {
            increased++;
        }
        last = current;
        prevprev = prev;
        #endif
        prev = n;
    }

    cout << increased << endl;
    return 0;
}
