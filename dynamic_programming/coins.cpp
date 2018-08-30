//
// Created by caizhili on 2018-8-30.
//

//@brief
// 面值 1, 3, 5 硬币中选择最少的硬币个数筹够 11 元。

void SelectNumCoins() {
    std::vector<int> coins{1, 3, 5};
    std::vector<int> dp(12, INT32_MAX);
    dp[0] = 0;
    for (unsigned int i = 1; i < dp.size(); ++i) {
        for (unsigned int j = 0; j < coins.size(); ++j) {
            if (coins[j] <= i) {
                dp[i] = std::min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
    }

    for (const auto &itr : dp) {
        cout << itr << endl;
    }
    cout << "end" << endl;
}

