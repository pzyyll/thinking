#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Direct {
    UP = 1,
    LEFT,
    UPLEFT,
};

typedef std::vector<int> Column;
typedef std::vector<Column> Matrix;
typedef std::pair<Matrix, Matrix> ResPair;

ResPair Lcs(const std::vector<char> x, const std::vector<char> y) {
    int len = 0;

    Matrix c(x.size() + 1, Column(y.size() + 1, 0));
    Matrix d = c;

    for (unsigned i = 1; i <= x.size(); ++i) {
        for (unsigned j = 1; j <= y.size(); ++j) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                d[i][j] = UPLEFT;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                d[i][j] = UP;
            } else {
                c[i][j] = c[i][j - 1];
                d[i][j] = LEFT;
            }
        }
    }


    for (unsigned i = 0; i < c.size(); ++i) {
        for (unsigned j = 0; j < c[i].size(); ++j) {
            cout << c[i][j];
            switch (d[i][j]) {
            case UP:
                cout << ":Up ";
                break;
            case LEFT:
                cout << ":Lt ";
                break;
            case UPLEFT:
                cout << ":UL ";
                break;
            default:
                cout << " ";
                break;
            }
        }
        cout << endl;
    }


    return std::make_pair(c, d);
}


int main() {

    //std::vector<char> x{'B','D','C','A','B','A'};
    //std::vector<char> y{'A','B','C','B','D','A','B'};
    string xstr("BDCABA");
    string ystr("ABCBDAB");
    std::vector<char> x(xstr.begin(), xstr.end());
    std::vector<char> y(ystr.begin(), ystr.end());

    Lcs(y, x);

    return 0;
}

