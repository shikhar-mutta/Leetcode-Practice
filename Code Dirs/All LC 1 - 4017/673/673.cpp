// Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: classic LIS DP with a parallel count array; len[i]=longest increasing subsequence ending at i, cnt[i]=number of such subsequences. For each j<i with nums[j]<nums[i], extend or accumulate counts.
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> len(n, 1), cnt(n, 1);
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    } else if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            maxLen = max(maxLen, len[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) if (len[i] == maxLen) res += cnt[i];
        return res;
    }
};
