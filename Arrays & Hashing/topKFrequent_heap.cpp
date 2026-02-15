#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;
        unordered_map<int,int> mp;

        // Step 1: Frequency count
        for(int num : nums){
            mp[num]++;
        }

        // Step 2: Max heap (frequency, number)
        priority_queue<pair<int,int>> pq;

        for(auto it : mp){
            pq.push({it.second, it.first});
        }

        // Step 3: Extract top k elements
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
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