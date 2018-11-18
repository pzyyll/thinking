#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int n = 0;
void Init(vector<int> &data, const int sizen) {
    n = 1;
    while (n < sizen) n *= 2;

    data.resize(n * 2);
    std::fill(data.begin(), data.end(), std::numeric_limits<int>::max());
}
void Update(vector<int> &data, const int i, const int val) {
    int k = i + (n - 1);
    data[k] = val;

    while (k > 0) {
        k = (k - 1) / 2; // get parent idx
        data[k] = std::min(data[k * 2 + 1], data[k * 2 + 2]);
    }
}
int Query(vector<int> &data, const int a, const int b, const int k, const int l, const int r) {
    if (r <= a || b <= l) return std::numeric_limits<int>::max();
    if (a <= l && r <= b)
        return data[k];

    int vl = Query(data, a, b, k * 2 + 1, l, (l + r) / 2);
    int vr = Query(data, a, b, k * 2 + 2, (l + r) / 2, r);
    return std::min(vl, vr);

}

int Mininum(vector<int> &nums, const int a, const int b) {
    vector<int> data;
    Init(data, nums.size());

    for (unsigned i = 0; i < nums.size(); ++i) {
        Update(data, i, nums[i]);
    }

    return Query(data, a, b, 0, 0, nums.size());
}

int main() {
    vector<int> nums{2,1,4,2,0,8,90};

    cout << Mininum(nums, 2, 4) << endl;

    int i = 12;
    cout << (i&-i) << endl;
    cout << "end1" << endl;
    return 0;
}
