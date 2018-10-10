#include <iostream>
#include <vector>
#include <string>

const unsigned N = 100;

using namespace std;

int main() {
    std::vector<double> p{0, 0.15, 0.10, 0.05, 0.10, 0.20};
    std::vector<double> q{0.05, 0.10, 0.05, 0.05, 0.05, 0.10};


    double e[N][N] = {0};
    double w[N][N] = {0};
    double root[N][N] = {0};

    unsigned n = p.size() - 1;
    for (unsigned i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (unsigned i = 1; i <= n; ++i) {
        for (unsigned j = i; j < n; ++j) {
            e[i][j] = INT32_MAX;
            w[i][j] = w[i][j - 1] + p[i] + q[i];
            for (unsigned r = i; r <= j; ++r) {
                double tmp = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (tmp < e[i][j]) {
                    e[i][j] = tmp;
                    root[i][j] = r;
                }
            }

            cout << e[i][j] << " ";
        }
        cout << endl;
    }


    cout << "end" << endl;
    return 0;
}
