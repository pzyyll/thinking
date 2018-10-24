#include <iostream>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, 0));

        int last_res = 0;
        for (unsigned i = 1; i <= grid.size(); ++i) {
            for (unsigned j = 1; j <= grid[i - 1].size(); ++j) {
                dp[i][j] = grid[i - 1][j - 1] + min(dp[i - 1][j], dp[i][j - 1]);
                last_res = dp[i][j];
            }
        }

        return last_res;
    }

};


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid[0].size() + 1, INT32_MAX));

        int last_res = 0;
        for (unsigned i = 1; i <= grid.size(); ++i) {
            for (unsigned j = 1; j <= grid[i - 1].size(); ++j) {
                if (1 == i && 1 == j) {
                    dp[i][j] = grid[i - 1][j - 1];
                } else {
                    dp[i][j] = grid[i - 1][j - 1] + min(dp[i][j - 1], dp[i - 1][j]);
                }
                last_res = dp[i][j];
            }
        }
    }
}


int main() {
    cout << "end" << endl;
    return 0;
}
