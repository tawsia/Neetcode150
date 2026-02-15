#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Step 1: Frequency count
        unordered_map<int,int> mp;

        for(int num : nums){
            mp[num]++;
        }

        // Step 2: Create buckets
        // Index = frequency
        vector<vector<int>> bucket(nums.size() + 1);

        for(auto it : mp){
            int num = it.first;
            int freq = it.second;

            bucket[freq].push_back(num);
        }

        // Step 3: Collect top k elements
        vector<int> ans;

        for(int i = bucket.size() - 1; i >= 0 && ans.size() < k; i--){

            for(int num : bucket[i]){
                ans.push_back(num);

                if(ans.size() == k)
                    break;
            }
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    vector<int> result = sol.topKFrequent(nums, k);

    cout << "Top K Frequent Elements: ";
    for(int num : result){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}