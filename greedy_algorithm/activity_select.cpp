#include <iostream>
#include <vector>

using namespace std;


vector<int> RecursiveActivitySelector(
        const vector<int> &s, const vector<int> &f,
        const int k, const int n) {

    vector<int> res;

    int m = k + 1;
    while (m <= n && s[m] < f[k])
        ++m;

    if (m <= n) {
        res.push_back(m);
        vector<int> nres = RecursiveActivitySelector(s, f,  m, n);
        res.insert(res.end(), nres.begin(), nres.end());
        return res;
    } else {
        return vector<int>();
    }
}

vector<int> GreedySelector(const vector<int> &s, const vector<int> &f) {

    int n = s.size() - 1;
    vector<int> res{1};
    int k = 1;
    for (unsigned m = 2; m <= n; ++m) {
        if (s[m] >= f[k]) {
            res.push_back(m);
            k = m;
        }
    }

    return res;
}


int main() {
    vector<int> vec_s{0, 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12};
    vector<int> vec_f{0, 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16};


    auto vec_res = GreedySelector(vec_s, vec_f);//RecursiveActivitySelector(vec_s, vec_f, 0, vec_s.size() - 1);

    for (auto itr : vec_res) {
        cout << itr << " ";
    }
    cout << endl;

    cout << "end" << endl;
    return 0;
}
