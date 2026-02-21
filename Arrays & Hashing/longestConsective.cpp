#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.empty()) return 0;

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for(int num : st) {

            // Only start sequence if num-1 is NOT present
            if(st.find(num - 1) == st.end()) {

                int current = num;
                int count = 1;

                while(st.find(current + 1) != st.end()) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {100,4,200,1,3,2};

    cout << "Longest Consecutive Length: "
         << sol.longestConsecutive(nums) << endl;

    return 0;
}