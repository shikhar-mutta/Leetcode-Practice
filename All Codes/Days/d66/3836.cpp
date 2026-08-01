// Link: https://leetcode.com/problems/maximum-score-using-exactly-k-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n*m*k)  SC: O(n*m*k)
// Approach: choose exactly k index pairs (i1<i2<...<ik into nums1,
// j1<j2<...<jk into nums2 independently) maximizing sum of nums1[i]*
// nums2[j]. DP f[i][j][t] = best score using nums1[0..i-1], nums2[0..j-1]
// with exactly t pairs placed so far; transitions either skip the current
// nums1 or nums2 element, or use them together as the t-th pair.
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        const long long NEG = LLONG_MIN / 2;
        vector<vector<vector<long long>>> f(n + 1, vector<vector<long long>>(m + 1, vector<long long>(k + 1, NEG)));
        f[0][0][0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int t = 0; t <= k; t++) {
                    if (i > 0) f[i][j][t] = max(f[i][j][t], f[i-1][j][t]);
                    if (j > 0) f[i][j][t] = max(f[i][j][t], f[i][j-1][t]);
                    if (i > 0 && j > 0 && t > 0 && f[i-1][j-1][t-1] > NEG) {
                        f[i][j][t] = max(f[i][j][t], f[i-1][j-1][t-1] + (long long)nums1[i-1] * nums2[j-1]);
                    }
                }
            }
        }
        return f[n][m][k];
    }
};
