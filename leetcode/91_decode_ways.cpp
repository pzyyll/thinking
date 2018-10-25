#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s.size() <= 1) return (s[0] == '0' ? 0 : 1);

        //vector<int> dp(s.size() + 10, 0);


        //dp[0] = 1;
        //dp[1] = 1;
        unsigned last_pre = (s[0] == '0' ? 0 : 1);
        unsigned pre = last_pre;
        unsigned dp = 0;
        for (unsigned i = 2; i <= s.size(); ++i) {
            int cvnum = std::stoi(s.substr(i - 2, 2));
            int units = cvnum % 10;
            int deci = cvnum / 10;
            if (units == 0 && (1 <= cvnum && cvnum <= 26)) {
                dp = last_pre;
            } else if (units == 0) {
                dp = 0;
            } else if (deci == 0) {
                dp = pre;
            } else if (1 <= cvnum && cvnum <= 26) {
                //dp[i] = dp[i - 1] + dp[i - 2];
                dp = pre + last_pre;
            } else {
                //dp[i] = dp[i - 1];
                dp = pre;
            }
            last_pre = pre;
            pre = dp;
        }

        return dp;
    }

};

int main() {

    Solution solu;

    cout << solu.numDecodings("111901911111") << endl;

    cout << "end" << endl;
    return 0;
}
