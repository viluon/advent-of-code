#define PART2

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#ifndef PART2
#include <set>
#else
#include <map>
#include <functional>
#endif

#ifdef PART2
bool numeric(const std::string& s) {
    return s.find_first_not_of("0123456789") == std::string::npos;
}

bool is_year(const std::string& s, int l, int h) {
    if (s.length() != 4 || !numeric(s)) {
        return false;
    }

    int n = stoi(s);
    return n >= l && n < h;
}
#endif

int main() {
    using namespace std;

    string line;
    int valid = 0;
    #ifndef PART2
    set<string> required = {
        "byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"
    };
    set<string> passport;
    #else
    map<string, function<bool(const string &)>> required = {
        {"byr", [](const string &s) {
            return is_year(s, 1920, 2003);
        }},
        {"iyr", [](const string &s) {
            return is_year(s, 2010, 2021);
        }},
        {"eyr", [](const string &s) {
            return is_year(s, 2020, 2031);
        }},
        {"hgt", [](const string &s) {
            if (s.length() < 3) {
                return false;
            }
            size_t n_len = s.length() - 2;
            auto n_ = s.substr(0, n_len);
            if (!numeric(n_)) {
                return false;
            }

            int n = stoi(n_);
            if (0 == s.compare(n_len, 2, "in")) {
                return n >= 59 && n <= 76;
            } else if (0 == s.compare(n_len, 2, "cm")) {
                return n >= 150 && n <= 193;
            }
            return false;
        }},
        {"hcl", [](const string &s) {
            return s[0] == '#' && s.length() == 7 && s.find_first_not_of("0123456789abcdef", 1) == string::npos;
        }},
        {"ecl", [](const string &s) {
            return s == "amb" || s == "blu" || s == "brn" ||
                   s == "gry" || s == "grn" || s == "hzl" || s == "oth";
        }},
        {"pid", [](const string &s) {
            return s.length() == 9 && numeric(s);
        }},
    };
    map<string, string> passport;
    #endif
    while (getline(cin, line)) {
        if (line == "") {
            // determine validity
            #ifndef PART2
            set<string> intersect;
            set_intersection(required.begin(), required.end(),
                             passport.begin(), passport.end(),
                             std::inserter(intersect, intersect.begin()));
            if (intersect == required) {
                valid++;
            }
            #else
            bool ok = true;
            for (auto entry : required) {
                auto k = entry.first;
                auto check = entry.second;
                ok &= passport.count(k) == 1 && check(passport[k]);
            }
            if (ok) {
                valid++;
            }
            #endif
            passport.clear();
        }

        istringstream line_ss(line);
        string word;
        while (getline(line_ss, word, ' ')) {
            istringstream word_ss(word);
            #ifndef PART2
            string key;
            if (getline(word_ss, key, ':')) {
                passport.insert(key);
            }
            #else
            string key, value;
            if (getline(word_ss, key, ':') && getline(word_ss, value, ':')) {
                passport.insert({key, value});
            }
            #endif
        }
    }

    cout << valid << endl;

    return 0;
}
