#define PART2

#include <iostream>
#include <string>

int main() {
    using namespace std;

    int n = 0;
    string line;
    #ifndef PART2
    bool answers[256] = {false};
    #else
    bool answers[256] = {};
    for (int i = 0; i < 256; i++) {
        answers[i] = true;
    }
    #endif

    while (getline(cin, line)) {
        if (line == "") {
            int count = 0;
            for (int i = 0; i < 256; i++) {
                count += answers[i];
                #ifndef PART2
                answers[i] = false;
                #else
                answers[i] = true;
                #endif
            }
            n += count;
        }
        #ifndef PART2
        for (char ans : line) {
            answers[(unsigned)ans] |= true;
        }
        #else
        else {
            for (int i = 0; i < 256; i++) {
                if (line.find(i) == string::npos) {
                    answers[i] = false;
                }
            }
        }
        #endif
    }

    cout << n << endl;

    return 0;
}
