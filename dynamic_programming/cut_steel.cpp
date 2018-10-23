//
// Created by caizhili on 2018-8-30.
//

#include <vector>
#include <iostream>

using namespace std;

// @brief 算法导论动态规划篇-钢条切割，自低向上实现
int CutSteel(const std::vector<int> &v, const std::vector<int> &p, const int length) {
    int opt_val = -1;
    std::vector<int> dp(length + 1, 0);
    std::vector<int> s(length + 1, 0);

    for (unsigned i = 1; i < dp.size(); ++i) {
        int q = -1;
        for (unsigned j = 0; j < v.size() && v[j] <= i; ++j) {
            if (q < (dp[i - v[j]] + p[j])) {
                q = dp[i - v[j]] + p[j];
                s[i] = v[j];
            }
            //dp[i] = std::max(dp[i], dp[i - v[j]] + p[j]);
            //if (opt_val < dp[i]) opt_val = dp[i];
        }
        dp[i] = q;
        if (opt_val < q) opt_val = q;
    }

    for (const auto &itr : dp) {
        cout << itr << endl;
    }

    cout << "--" << endl;
    int temp_len = length;
    while (temp_len > 0) {
        cout << s[temp_len] << ", ";
        temp_len -= s[temp_len];
    }
    cout << endl << "--end" << endl;

    return opt_val;
}

int main() {

    cout << "hello." << endl;
    return 0;
}
