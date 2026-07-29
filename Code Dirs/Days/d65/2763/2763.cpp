// Link: https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(N)
// Approach: imbalance of a sorted array = (distinctCount-1) - (number of consecutive-integer
// pairs among its distinct values), since only gaps between DISTINCT values matter (duplicates
// contribute a diff of 0, never counted). For each left endpoint i, extend j and maintain
// distinctCount and adjPairs incrementally, updating only on a value's first appearance in [i,j].
class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> present(n + 2, false);
            int distinctCount = 0, adjPairs = 0;
            for (int j = i; j < n; j++) {
                int v = nums[j];
                if (!present[v]) {
                    present[v] = true;
                    distinctCount++;
                    if (v >= 1 && present[v-1]) adjPairs++;
                    if (v + 1 <= n && present[v+1]) adjPairs++;
                }
                total += max(0, distinctCount - 1 - adjPairs);
            }
        }
        return (int)total;
    }
};
