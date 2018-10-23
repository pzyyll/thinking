//
// Created by caizhili on 2018-8-30.
//

#include <vector>
#include <iostream>

using namespace std;

//@brief
// 求序列中最长非降子序列长度
int LongestSeq(const std::vector<int> &seq) {
    std::vector<int> dp(seq.size() + 1, 0);

    for (unsigned i = 0; i < seq.size(); ++i) {
        dp[i] = 1;
        for (unsigned j = 0; j < i; ++j) {
            if (seq[j] <= seq[i])
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
    }

    return dp[seq.size() - 1];
}

int main() {

    cout << "hello." << endl;
    return 0;
}
