#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() <= 1) return nums[0];

    int dp_max = nums[0], sum = 0;
    for (unsigned i = 1; i < nums.size(); ++i) {
        sum = nums[i];
        dp_max = max(sum, dp_max);
        for (int j = i - 1; j >= 0; --j) {
            sum += nums[j];
            dp_max = max(sum, dp_max);
        }
    }

    return dp_max;
}


int main() {
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

    cout << maxSubArray(nums) << endl;

    cout << "end" << endl;
    return 0;
}
