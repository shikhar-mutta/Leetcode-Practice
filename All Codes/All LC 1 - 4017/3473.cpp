// Link: https://leetcode.com/problems/sum-of-k-subarrays-with-length-at-least-m/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * k) SC: O(n * k)
//  Approach: dp[j][i] = max sum using exactly j non-overlapping subarrays
//  (each length >= m) chosen from the first i elements. Either skip
//  element i (dp[j][i-1]), or end a new subarray exactly at i with some
//  length L >= m: dp[j][i] = max_p (dp[j-1][p] - prefix[p]) + prefix[i]
//  for p <= i-m. The inner max is tracked as a running best as i grows,
//  avoiding an O(n) inner scan.
class Solution
{
public:
    int maxSum(vector<int> &nums, int k, int m)
    {
        int n = nums.size();
        // nums 的前缀和. 左闭右开.
        vector<int> s(n + 1);
        partial_sum(nums.begin(), nums.end(), s.begin() + 1);

        // 前 n 个数中，选 k 组、且每组至少为 m 长度，的最大值
        vector f(k + 1, vector<int>(n + 1));
        for (int i = 1; i <= k; i++)
        {
            // INT_MIN 表示不合法的状态
            f[i][i * m - 1] = INT_MIN;
            int mx = INT_MIN;
            // j, 左边至少留 i * m, 右边至少留 (k - i) * m .
            for (int j = i * m; j <= n - (k - i) * m; j++)
            {
                // mx 表示遍历过程中最大的 f[i-1][L]-s[L]，其中 L 在区间
                // [(i-1)*m, j-m] 中
                mx = max(mx, f[i - 1][j - m] - s[j - m]);
                f[i][j] = max(f[i][j - 1], mx + s[j]); // 不选 vs 选
            }
        }
        return f[k][n];
    }
};