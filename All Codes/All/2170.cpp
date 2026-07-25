// Link: https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + maxVal)
// SC: O(maxVal)
// Approach: count each value's frequency split by index parity (even/odd
// position). Sweep candidate values 1..1e5, tracking the running max
// frequency seen so far at even positions (j) and odd positions (k). For
// each value i, the best alternating array using i as one parity's value
// and some other (already-seen, distinct) value as the other parity's value
// scores freq[i][0]+k or freq[i][1]+j; keep the best across all i, then
// answer = n - best (elements that must change).
class Solution {
    int freq[100005][2];

public:
    int minimumOperations(vector<int>& nums) {
        memset(freq, 0, sizeof(freq));
        int n = nums.size(), i, j, k, ans = 0;
        for (i = 0; i < n; i++) {
            freq[nums[i]][i & 1]++;
        }
        for (i = 1, j = k = 0; i <= 100000; i++) {
            // Add the maximum frequency of odd indexes to maximum frequency
            // even indexes and vice versa, it will give us how many elements we
            // don't need to change.
            ans = max(ans, max(freq[i][0] + k, freq[i][1] + j));
            j = max(j, freq[i][0]);
            k = max(k, freq[i][1]);
        }
        return n - ans;
    }
};
