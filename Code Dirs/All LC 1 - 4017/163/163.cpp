// Link: https://leetcode.com/problems/missing-ranges/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1) extra (excluding output)
// Approach: walk the sorted array with a running "expected next value" pointer, emit a range whenever
// there's a gap before the current number, and a trailing range after the last number up to upper
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long long prev = (long long)lower - 1;
        for (int i = 0; i <= (int)nums.size(); i++) {
            long long cur = (i == (int)nums.size()) ? (long long)upper + 1 : nums[i];
            if (cur - prev >= 2) {
                if (cur - prev == 2) res.push_back(to_string(prev + 1));
                else res.push_back(to_string(prev + 1) + "->" + to_string(cur - 1));
            }
            prev = cur;
        }
        return res;
    }
};
