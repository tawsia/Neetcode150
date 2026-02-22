#include <vector>
using namespace std;

class Solution {
public:
    // numbers: sorted in non-decreasing order
    // target: sum to find
    // Returns 1-indexed positions [index1, index2] with index1 < index2
    // Assumes exactly one solution exists; uses O(1) extra space
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;                   // left pointer (0-based)
        int j = (int)numbers.size() - 1; // right pointer (0-based)

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (sum == target) {
                // Found the pair; convert to 1-indexed before returning
                return { i + 1, j + 1 };
            } else if (sum > target) {
                // Sum too large; need smaller numbers -> move right pointer left
                --j;
            } else {
                // Sum too small; need larger numbers -> move left pointer right
                ++i;
            }
        }

        // Given the problem guarantees exactly one solution, this line
        // should never be reached. Returning an empty vector as a fallback.
        return {};
    }
};