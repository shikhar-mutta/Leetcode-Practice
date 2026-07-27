// Link: https://leetcode.com/problems/minimum-cost-to-equalize-arrays-using-swaps/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: within-array swaps are free, so only the multiset of values
// in each array matters, not order. For the arrays to end up identical,
// each value's combined total count across both arrays must split evenly
// (else -1). A cross-swap moves one unit of some value from array1 to
// array2 while simultaneously moving one unit of another value from
// array2 to array1, so it fixes one surplus-in-1 value and one
// deficit-in-1 value at once. The minimum ops therefore equals the total
// surplus (sum of positive count1[v] - target[v]).
class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cntA, total;
        for (int x : nums1) { cntA[x]++; total[x]++; }
        for (int x : nums2) total[x]++;

        for (auto& [v, t] : total) if (t % 2 != 0) return -1;

        int ops = 0;
        for (auto& [v, t] : total) {
            int target = t / 2;
            int a = cntA.count(v) ? cntA[v] : 0;
            if (a > target) ops += a - target;
        }
        return ops;
    }
};
