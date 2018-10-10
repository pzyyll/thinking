#include <iostream>
#include <vector>

using namespace std;


int main() {
    std::vector<int> test_case{7,1,5,3,6,4};

    int res = 0;
    int min_idx = 0;
    for (unsigned i = 1; i < test_case.size(); ++i) {
        int temp =0;
        if (test_case[i] < test_case[min_idx])
            min_idx = i;
        else
            res = (temp = test_case[i] - test_case[min_idx]) > res ? temp : res;
    }

    cout << res << endl;

    return 0;
}
