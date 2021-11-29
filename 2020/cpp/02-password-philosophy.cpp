#include <iostream>
#include <string>

#define PART2

int main() {
    using namespace std;
    char skip;
    int valid = 0;

    for (int l; cin >> l;) {
        int h;
        cin >> h;
        h *= -1;
        char letter;
        string password;
        cin >> letter >> skip;
        cin >> password;

        #ifndef PART2
        int occurrences = 0;
        for (char ch : password) {
            if (ch == letter) {
                occurrences++;
            }
        }

        if (occurrences >= l && occurrences <= h) {
            valid++;
        }
        #else
        bool letter_at_l = password[l - 1] == letter;
        bool letter_at_h = password[h - 1] == letter;
        if ((letter_at_l != letter_at_h) && (letter_at_l || letter_at_h)) {
            valid++;
        }
        #endif
    }

    cout << valid << endl;

    return 0;
}
