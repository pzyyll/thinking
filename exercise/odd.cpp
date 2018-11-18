#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::vector<int> nums{1,1,2,2,3,4,4, 3, 7, 3, 7, 2, 3};
    int res = nums[0];
    for (unsigned i = 1; i < nums.size(); ++i) {
        res ^= nums[i];
    }
    cout << res << endl;


    std::vector<int> nums2{1,1,2,2,3,4,5,5};
    res = nums2[0];
    for (unsigned i = 1; i < nums2.size(); ++i) {
        res ^= nums2[i];
    }
    cout << res << endl;

    int low_bit = res&-res;
    //while (0 == (res & low_bit)) low_bit << 1;
    cout << low_bit << endl;


    unsigned a = 0, b = 0;
    for (unsigned i = 0; i < nums2.size(); ++i) {
        if (nums2[i] & low_bit) {
            a ^= nums2[i];
        } else {
            b ^= nums2[i];
        }
    }

    cout << a << endl;
    cout << b << endl;

    return 0;
}
