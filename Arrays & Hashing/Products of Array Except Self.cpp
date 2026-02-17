#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        // answer array initialized with 1
        vector<int> ans(n, 1);

        // Step 1: Prefix (left product)
        int prefix = 1;
        for(int i = 0; i < n; i++) {
            ans[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Suffix (right product)
        int suffix = 1;
        for(int i = n - 1; i >= 0; i--) {
            ans[i] *= suffix;
            suffix *= nums[i];
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    cout << "Output: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}