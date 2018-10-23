#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;
        if (m == 1 || n == 1) return 1;

        vector<vector<int>> kRecord(n + 1, vector<int>(m + 1, 0));

        for (unsigned i = 0; i < n; ++i) {
            for (unsigned j = 0; j < m; ++j) {
                if (i == 0 || j == 0) {
                    kRecord[i][j] = 1;
                } else {
                    kRecord[i][j] = kRecord[i][j - 1] + kRecord[i - 1][j];
                }
            }
        }

        return kRecord[n - 1][m - 1];
    }
};

int main() {

    Solution slo;
    cout << slo.uniquePaths(7, 3) << endl;;
    cout << "end" << endl;
    return 0;
}
