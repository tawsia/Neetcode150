#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        unordered_map<char, int> mp;

        for(char c : s) mp[c]++;
        for(char c : t) mp[c]--;

        for(auto it : mp) {
            if(it.second != 0) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    string s = "listen";
    string t = "silent";

    if(sol.isAnagram(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}