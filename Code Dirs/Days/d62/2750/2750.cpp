// Link: https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: every split boundary must fall strictly between two consecutive
// 1s (so each part keeps exactly one 1). Between consecutive 1s at distance
// d = i - prev, there are d independent choices of where to cut, so the
// total way count is the product of gaps between successive 1s. No 1s at all
// means no valid split (0 ways).
class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        const long long MOD = 1000000007;
        int prev = -1;
        long long ways = 1;

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                if (prev != -1)
                    ways = ways * (i - prev) % MOD;
                prev = i;
            }
        }
        return prev == -1 ? 0 : (int)ways;
    }
};
