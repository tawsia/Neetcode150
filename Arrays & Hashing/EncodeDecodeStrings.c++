#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    // ENCODE
    string encode(vector<string>& strs) {

        string res = "";

        for(string st : strs) {
            res += to_string(st.size()) + "#" + st;
        }

        return res;
    }

    // DECODE
    vector<string> decode(string s) {

        vector<string> ans;
        int i = 0;

        while(i < s.size()) {

            // Step 1: find '#'
            int j = i;
            while(s[j] != '#') {
                j++;
            }

            // Step 2: length
            int len = stoi(s.substr(i, j - i));

            // Step 3: extract word
            string word = s.substr(j + 1, len);
            ans.push_back(word);

            // Step 4: move pointer
            i = j + 1 + len;
        }

        return ans;
    }
};