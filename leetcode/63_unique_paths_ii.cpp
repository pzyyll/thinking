#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty()) return 0;

        vector<vector<int>> kRecord(obstacleGrid.size() + 1, vector<int>(obstacleGrid[0].size() + 1, 0));

        int last_res = 0;
        for (unsigned i = 1; i <= obstacleGrid.size(); ++i) {
            for (unsigned j = 1; j <= obstacleGrid[i - 1].size(); ++j) {
                if (obstacleGrid[i - 1][j - 1] == 1) {
                    kRecord[i][j] = 0;
                } else if (i == 1 && j == 1) {
                    kRecord[i][j] = 1;
                } else {
                    kRecord[i][j] = kRecord[i][j - 1] + kRecord[i - 1][j];
                }
                last_res = kRecord[i][j];
            }
        }

        return last_res;
    }
};

int main() {

    cout << "end" << endl;
    return 0;
}
