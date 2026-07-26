// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the frequency map
// Approach: count each value's frequency. A value with count 1 can never be
// removed (only pairs/triples of equal values allowed), so the whole array is
// impossible to empty. Otherwise each value's count needs ceil(count/3) ops
// (take triples greedily, at most one leftover pair/single absorbed into a
// final triple-sized op since count>=2 here).
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto i : nums)
            mp[i]++;
        int op = 0;
        for (auto it : mp) {
            int c = it.second;
            if (c < 2)
                return -1;
            op += (c + 2) / 3;
        }
        return op;
    }
};
