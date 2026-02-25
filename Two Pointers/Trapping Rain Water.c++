#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int trap(vector<int>& height) {
           if (height.empty()) {
                return 0;
            }
    
            int l = 0, r = height.size() - 1;
            int leftMax = height[l], rightMax = height[r];
            int res = 0;
            while (l < r) {
                if (leftMax < rightMax) {
                    l++;
                    leftMax = max(leftMax, height[l]);
                    res += leftMax - height[l];
                } else {
                    r--;
                    rightMax = max(rightMax, height[r]);
                    res += rightMax - height[r];
                }
            }
            return res;  
        }
    };
int main() {
    Solution s;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(height) << endl; // Output: 6
    return 0;
}