#include <iostream>
#include <vector>

int main() {
    using namespace std;

    vector<int> numbers;
    int n;
    while (cin >> n) {
        numbers.push_back(n);
    }

    for (int n : numbers) {
        for (int m : numbers) {
            for (int p : numbers) {
                if (n + m + p == 2020) {
                    cout << n * m * p << endl;
                    return 0;
                }
            }
        }
    }

    return 1;
}
