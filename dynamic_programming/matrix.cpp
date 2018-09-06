//
// Created by caizhili on 2018-9-6.
//
#include <iostream>
#include <vector>

using namespace std;


class Matrix {
public:
    Matrix(const int n, const int m, const int init = 0) :
            _grid(n, std::vector<int>(m, init)),
            _rows(n), _cols(m) {

    }

    void Print() const {
        for (const auto itr : _grid) {
            for (const auto secitr : itr) {
                cout << secitr << " ";
            }
            cout << endl;
        }
    }

    std::vector<int> &operator[](const unsigned row) {
        return _grid[row];
    }

    const std::vector<int> &operator[](const unsigned row) const {
        return _grid[row];
    }

    int rows() const { return _rows; }
    int cols() const { return _cols; }

private:
    std::vector<std::vector<int>> _grid;
    int _rows;
    int _cols;
};


Matrix operator *(const Matrix &m1, const Matrix &m2) {
    if (m1.cols() != m2.rows()) {
        return Matrix(0, 0);
    }

    Matrix res(m1.rows(), m2.cols());

    for (unsigned i = 0; i < m1.rows(); ++i) {
        for (unsigned j = 0; j < m2.cols(); ++j) {
            res[i][j] = 0;
            for (unsigned k = 0; k < m1.cols(); ++k) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return res;
}

ostream &operator<<(std::ostream &out, const Matrix &m) {
    m.Print();
    return out;
}

unsigned long GetOperatorTimes(const Matrix &m1, const Matrix &m2) {
    return ((unsigned long)m1.rows() * m2.rows() * m2.cols());
}


int main() {
    Matrix m1(10, 100, 2);
    Matrix m2(100, 5, 3);
    Matrix m3(5, 50, 1);

    //Matrix res = m1 * (m2 * m3);

    cout << GetOperatorTimes(m2, m3) << endl;
    //cout << res;


    return 0;
}
