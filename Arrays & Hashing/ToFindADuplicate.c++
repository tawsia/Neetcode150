#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 1; i++) {
            if(nums[i] == nums[i + 1]) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 1};

    if(sol.hasDuplicate(nums))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}