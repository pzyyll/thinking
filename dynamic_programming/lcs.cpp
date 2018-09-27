#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

enum Direct {
    UP = 1,
    LEFT,
    UPLEFT,
};

typedef std::vector<int> Column;
typedef std::vector<Column> Matrix;
typedef std::pair<Matrix, Matrix> ResPair;

int LcsDpfC(Matrix &c, Matrix &d,
        const std::vector<char> &x, const unsigned i,
        const std::vector<char> &y, const unsigned j) {
    if (i == 0 || j == 0)
        return 0;
    if (c[i][j] != 0)
        return c[i][j];

    if (x[i - 1] == y[j - 1]) {
        c[i][j] = LcsDpfC(c, d, x, i - 1, y, j - 1) + 1;
        d[i][j] = UPLEFT;
    } else {
        int res1 = LcsDpfC(c, d, x, i - 1, y, j);
        int res2 = LcsDpfC(c, d, x, i, y, j - 1);

        c[i][j] = res1 >= res2 ? res1 : res2;
        d[i][j] = res1 >= res2 ? UP : LEFT;
    }

    return c[i][j];
}


// @brief 自顶向下
// 带备忘的自顶向下方法只会对需要用的子问题进行求解
ResPair LcsDpf(const std::vector<char> x, const std::vector<char> y) {
    Matrix c(x.size() + 1, Column(y.size() + 1, 0));
    Matrix d = c;

    LcsDpfC(c, d, x, x.size(), y, y.size());

    return ResPair(c, d);
}


// @brief 自底向上
// 自底向上会对每个子问题进行求解。
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

    return std::make_pair(c, d);
}


void PrintResolve(const Matrix &d, const int i, const int j, const std::vector<char> &x) {
    if (i == 0 || j == 0)
        return;

    switch (d[i][j]) {
    case UP:
        PrintResolve(d, i - 1, j, x);
        break;
    case LEFT:
        PrintResolve(d, i, j - 1, x);
        break;
    default:
        PrintResolve(d, i - 1, j - 1, x);
        cout << x[i - 1];
        break;
    }
}


void PrintResAll(const Matrix &c, const Matrix &d) {
    for (unsigned i = 0; i < c.size(); ++i) {
        for (unsigned j = 0; j < c[i].size(); ++j) {
            cout << setw(4) << c[i][j];
            switch (d[i][j]) {
            case UP:
                cout << ":Up";
                break;
            case LEFT:
                cout << ":Lt";
                break;
            case UPLEFT:
                cout << ":UL";
                break;
            default:
                cout << "   ";
                break;
            }
        }
        cout << endl;
    }
}


int main() {

    //std::vector<char> x{'B','D','C','A','B','A'};
    //std::vector<char> y{'A','B','C','B','D','A','B'};
    string xstr("BDCABA");
    string ystr("ABCBDAB");
    std::vector<char> x(xstr.begin(), xstr.end());
    std::vector<char> y(ystr.begin(), ystr.end());

    cout << "只求解用到的子问题。" << endl;
    auto ress = LcsDpf(y, x);
    PrintResAll(ress.first, ress.second);
    PrintResolve(ress.second, y.size(), x.size(), y);
    cout << endl << endl;


    cout << "求解所有子问题。" << endl;
    ress = Lcs(y, x);
    PrintResAll(ress.first, ress.second);
    PrintResolve(ress.second, y.size(), x.size(), y);
    cout << endl;


    return 0;
}

