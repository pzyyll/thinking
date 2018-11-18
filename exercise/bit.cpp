#include <iostream>
#include <vector>

using namespace std;

int Sum(vector<int> &bit, int i) {
    int sum = 0;

    while (i > 0) {
        sum += bit[i];
        i -= i&-i;
    }
    return sum;
}

void Add(vector<int> &bit, int i, int val) {
    while (i <= bit.size()) {
        bit[i] += val;
        i += i&-i;
    }
}

int main() {
    std::vector<int> nums{1,2,3,4,5,6,7,8};
    std::vector<int> bit(nums.size() + 10, 0);

    for (unsigned i = 0; i < nums.size(); ++i) {
        Add(bit, i + 1, nums[i]);
    }

    cout << Sum(bit, 8) << endl;

    cout << "end" << endl;
    return 0;
}
