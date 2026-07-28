// Link: https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(1)
// Approach: classify each element into category 0 (<a), 1 ([a,b]), or
// 2 (>b). Since elements within a category are interchangeable, the
// minimum adjacent swaps equals the number of inversions of the
// category sequence, counted in O(n) using running counts per category.
class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const long long MOD = 1e9 + 7;
        long long cnt[3] = {0, 0, 0};
        long long total = 0;
        for (int x : nums) {
            int c = (x < a) ? 0 : (x <= b) ? 1 : 2;
            for (int k = c + 1; k < 3; k++) total += cnt[k];
            cnt[c]++;
        }
        return (int)(total % MOD);
    }
};
