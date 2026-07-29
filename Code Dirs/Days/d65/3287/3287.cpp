// Link: https://leetcode.com/problems/find-the-maximum-sequence-value-of-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*K*128), SC: O(N*K*128/64)
// Approach: values fit in 7 bits (OR results in [0,127]). For each prefix, track the SET of
// achievable OR-values using exactly c elements (as a 128-bit mask, DP over count); do the same
// from the suffix side. For every valid split point (k elements picked from the prefix, k from
// the suffix), cross every achievable left-OR against every achievable right-OR and XOR them,
// keeping the max.
class Solution {
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        // leftDp[i][c] = achievable OR-values using exactly c elements from nums[0..i-1]
        vector<vector<bitset<128>>> leftDp(n+1, vector<bitset<128>>(k+1));
        leftDp[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
            leftDp[i][0][0] = 1;
            for (int c = 1; c <= k; c++) {
                leftDp[i][c] = leftDp[i-1][c];
                for (int v = 0; v < 128; v++) {
                    if (leftDp[i-1][c-1][v]) leftDp[i][c][v | nums[i-1]] = 1;
                }
            }
        }

        vector<vector<bitset<128>>> rightDp(n+2, vector<bitset<128>>(k+1));
        rightDp[n+1][0][0] = 1;
        for (int i = n; i >= 1; i--) {
            rightDp[i][0][0] = 1;
            for (int c = 1; c <= k; c++) {
                rightDp[i][c] = rightDp[i+1][c];
                for (int v = 0; v < 128; v++) {
                    if (rightDp[i+1][c-1][v]) rightDp[i][c][v | nums[i-1]] = 1;
                }
            }
        }

        int ans = 0;
        for (int split = k; split <= n - k; split++) {
            auto& L = leftDp[split][k];
            auto& R = rightDp[split+1][k];
            for (int a = 0; a < 128; a++) {
                if (!L[a]) continue;
                for (int b = 0; b < 128; b++) {
                    if (!R[b]) continue;
                    ans = max(ans, a ^ b);
                }
            }
        }
        return ans;
    }
};
