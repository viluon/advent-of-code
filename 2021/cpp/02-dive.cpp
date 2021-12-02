#define PART2
#include <string>
#include <iostream>

int main() {
    using namespace std;

    string cmd;
    int pos = 0;
    int depth = 0;
    #ifdef PART2
    int aim = 0;
    #endif
    while (cin >> cmd) {
        int n;
        cin >> n;
        if (cmd == "forward") {
            pos += n;
            #ifdef PART2
            depth += aim * n;
            #endif
        } else if (cmd == "up") {
            #ifndef PART2
            depth -= n;
            #else
            aim -= n;
            #endif
        } else {
            #ifndef PART2
            depth += n;
            #else
            aim += n;
            #endif
        }
    }

    cout << pos * depth << endl;

    return 0;
}
