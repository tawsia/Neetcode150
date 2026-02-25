#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int maxArea(vector<int>& heights) {
             int l = 0;
            int r = heights.size() - 1;
            int res = 0;
    
            while (l < r) {
                int area = min(heights[l], heights[r]) * (r - l);
                res = max(res, area);
    
                if (heights[l] <= heights[r]) {
                    l++;
                } else {
                    r--;
                }
            }
            return res;
        }
    };
int main() {
    Solution s;
    vector<int> heights = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(heights) << endl; // Output: 49
    return 0;
}    
