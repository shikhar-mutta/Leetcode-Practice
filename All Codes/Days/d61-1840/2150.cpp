// Link: https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + maxVal)
// SC: O(maxVal)
// Approach: counting sort into a frequency array (offset by 1 so num=0
// doesn't need a negative index), then a number is lonely iff its own
// frequency is exactly 1 and neither neighboring value (num-1, num+1) is
// present in the array.
class Solution {
public:
    static std::vector<int> findLonely(const std::vector<int>& nums) {
        static int cnts[1'000'003];
        std::memset(cnts, 0, sizeof(cnts));
        for (const int num : nums) {
            ++cnts[num + 1];
        }
        std::vector<int> res{};
        for (const int num : nums) {
            if (cnts[num + 1] == 1 && cnts[num] == 0 && cnts[num + 2] == 0) {
                res.push_back(num);
            }
        }
        return res;
    }
};
