#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <string>
#include <sys/select.h>

using namespace std;

string kRecord[1000][1000];

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

int main() {
    string s("ccb");
    cout << LogestPalindrome(s) << endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
