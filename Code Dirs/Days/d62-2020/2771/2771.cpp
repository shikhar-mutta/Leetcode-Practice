// Link: https://leetcode.com/problems/longest-non-decreasing-subarray-from-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1)
// Approach: two-state DP — dp1 = length of the best non-decreasing sequence
// ending at index i-1 that chose a[i-1], dp2 = same but chose b[i-1]. At each
// i, the new dp1 (choosing a[i]) can extend from either previous choice
// (whichever is <= a[i]); same for dp2 with b[i]. Track the running max.
class Solution {
public:
    int maxNonDecreasingLength(vector<int>& a, vector<int>& b) {
        int res = 1, dp1 = 1, dp2 = 1, n = a.size(), t11, t12, t21, t22;
        for(int i = 1; i < n; i++) {
            t11 = a[i - 1] <= a[i] ? dp1 + 1 : 1;
            t12 = a[i - 1] <= b[i] ? dp1 + 1 : 1;
            t21 = b[i - 1] <= a[i] ? dp2 + 1 : 1;
            t22 = b[i - 1] <= b[i] ? dp2 + 1 : 1;
            dp1 = max(t11, t21);
            dp2 = max(t22, t12);
            res = max(res, max(dp1, dp2));
        }
        return res;
    }
};
