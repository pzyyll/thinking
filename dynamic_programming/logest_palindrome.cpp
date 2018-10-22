#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <sys/select.h>

using namespace std;

typedef vector<vector<string>> Vect2DString;
Vect2DString kRecord;

string LogestPalindrome(const string &s, const unsigned i, const unsigned j) {
    if (i == j) return s.substr(i, 1);
    if (i + 1 == j && s[i] == s[j]) return s.substr(i, j - i + 1);

    if (!kRecord[i][j].empty()) return kRecord[i][j];

    if (s[i] == s[j]) {
        kRecord[i][j] = string("") + s[i] + LogestPalindrome(s, i + 1, j - 1) + s[j];
        return kRecord[i][j];
    } else {
        string s1 = LogestPalindrome(s, i, j - 1);
        string s2 = LogestPalindrome(s, i + 1, j);
        kRecord[i][j] = s1.size() > s2.size() ? s1 : s2;
        return kRecord[i][j];
    }
}

string LogestPalindrome(string s) {
    if (s.empty()) return s;

    s = LogestPalindrome(s, 0, s.size() - 1);

    return s;
}

// @brief Bottom-Up
string LogestPalindromeBottomUp(string s) {
    if (s.empty()) return s;

    for (unsigned j = 0; j < s.size(); ++j) {
        for (unsigned i = j; i >= 0; --i) {
            if (i == j) {
                kRecord[i][j] = s[i];
            } else if (s[i] == s[j]) {
                kRecord[i][j] = string("") + s[i] +
                    (i + 1 == j ? "" : kRecord[i + 1][j - 1]) +
                    s[j];
            } else {
                string str1 = kRecord[i][j - 1];
                string str2 = kRecord[i + 1][j];
                kRecord[i][j] = (str1.size() > str2.size() ? str1 : str2);
            }

            if (i == 0) break;
        }
    }

    return kRecord[0][s.size() - 1];
}

int main() {

    string s;
    while (cin >> s) {
        kRecord = Vect2DString(s.size() + 1, vector<string>(s.size() + 1, ""));
        cout << LogestPalindromeBottomUp(s) << endl;
    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
