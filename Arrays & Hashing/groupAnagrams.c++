#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        // Process each string
        for(string s : strs) {

            int freq[26] = {0};

            // Count frequency of characters
            for(char c : s) {
                freq[c - 'a']++;
            }

            // Convert frequency array into unique key
            string key = "";
            for(int i = 0; i < 26; i++) {
                key += "#" + to_string(freq[i]);
            }

            // Group anagrams
            mp[key].push_back(s);
        }

        // Convert map values to answer
        vector<vector<string>> ans;

        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main() {

    Solution sol;

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

    vector<vector<string>> result = sol.groupAnagrams(strs);

    // Print result
    for(auto group : result) {
        cout << "[ ";
        for(string s : group) {
            cout << s << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}