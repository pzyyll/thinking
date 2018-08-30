//
// Created by czllo on 2018-8-29.
//

#include <iostream>
#include <vector>

using namespace std;

// @brief
// 平面上有N*M个格子，每个格子中放着一定数量的苹果。
// 你从左上角的格子开始， 每一步只能向下走或是向右走，
// 每次走到一个格子上就把格子里的苹果收集起来，
// 求最多能收集到多少个苹果。

// 输入样例
// 1 5 10 2 1
// 3 4 1 3 8
// 9 10 21 3 4
// 5 7 8 2 1
// 3 4 1 3 1

const unsigned N = 5 + 1;
const unsigned M = 5 + 1;

int main() {

    int grid[N][M] = {0};

    for (unsigned i = 1; i < N; ++i) {
        for (unsigned j = 1; j < M; ++j) {
            cin >> grid[i][j];
            //cout << grid[i][j] << " ";
        }
        //cout << endl;
    }


    int dp[N][M] = {0};
    for (unsigned i = 1; i < N; ++i) {
        for (unsigned j = 1; j < M; ++j) {
            dp[i][j] = grid[i][j] + std::max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    cout << "res------" << endl;

    for (unsigned i = 0; i < N; ++i) {
        for (unsigned j = 0; j < M; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << dp[N - 1][M - 1] << endl;

    return 0;
}
