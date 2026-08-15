// Link: https://leetcode.com/problems/sum-of-k-subarrays-with-length-at-least-m/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        vector<int> s(n + 1);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1);

        vector f(k + 1, vector<int>(n + 1));
        for (int i = 1; i <= k; i++) {
            f[i][i * m - 1] = INT_MIN;
            int mx = INT_MIN;
            for (int j = i * m; j <= n - (k - i) * m; j++) {
                mx = max(mx, f[i - 1][j - m] - s[j - m]);
                f[i][j] = max(f[i][j - 1], mx + s[j]);
            }
        }
        return f[k][n];
    }
};
