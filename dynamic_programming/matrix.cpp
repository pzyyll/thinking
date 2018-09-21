//
// Created by caizhili on 2018-9-6.
//
#include <iostream>
#include <vector>

using namespace std;


typedef std::pair<int, int> MatrixScale;

class Matrix {
public:
    Matrix(const int n, const int m, const int init = 0) :
            _grid(n, std::vector<int>(m, init)),
            _matrix_scale(n, m) {

    }

    void Print() const {
        for (const auto &itr : _grid) {
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

    int Rows() const { return _matrix_scale.first; }
    int Cols() const { return _matrix_scale.second; }

    const MatrixScale &matrix_scale() const { return _matrix_scale; }

private:
    std::vector<std::vector<int>> _grid;
    MatrixScale _matrix_scale;
};


Matrix operator *(const Matrix &m1, const Matrix &m2) {
    if (m1.Cols() != m2.Rows()) {
        return Matrix(0, 0);
    }

    Matrix res(m1.Rows(), m2.Cols());

    for (unsigned i = 0; i < m1.Rows(); ++i) {
        for (unsigned j = 0; j < m2.Cols(); ++j) {
            res[i][j] = 0;
            for (unsigned k = 0; k < m1.Cols(); ++k) {
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
    return ((unsigned long) m1.Rows() * m2.Rows() * m2.Cols());
}

MatrixScale GetMatrixMutiScale(const Matrix &m1, const Matrix &m2) {
    MatrixScale matrix_scale;

    if (m1.Cols() != m2.Rows()) return matrix_scale;

    matrix_scale.first = m1.Rows();
    matrix_scale.second = m2.Cols();

    return matrix_scale;
}


int main() {
    Matrix m1(10, 100, 2);
    Matrix m2(100, 5, 3);
    Matrix m3(5, 50, 1);

    Matrix res = m1 * (m2 * m3);

    //cout << GetOperatorTimes(m2, m3) << endl;
    //cout << GetOperatorTimes(m1, m2) << endl;

    //cout << GetMatrixMutiScale(m1, m2).first << endl;
    //cout << GetMatrixMutiScale(m1, m2).second << endl;
    cout << res;


    return 0;
}
