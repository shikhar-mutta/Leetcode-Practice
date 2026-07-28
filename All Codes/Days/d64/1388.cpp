// Link: https://leetcode.com/problems/pizza-with-3n-slices/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n^2)  SC: O(n^2)
// Approach: taking a slice forces both its neighbors to be skipped, so
// this is "pick n/3 non-adjacent elements to maximize sum" on a
// circular array. Handle the circularity by running the linear
// non-adjacent-selection DP twice — once excluding the last slice, once
// excluding the first — and taking the better result.
class Solution {
    int pickMax(vector<int>& arr, int k) {
        int m = arr.size();
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= k; j++) {
                int skip = dp[i - 1][j];
                int take = (i >= 2 ? dp[i - 2][j - 1] : 0) + arr[i - 1];
                dp[i][j] = max(skip, take);
            }
        }
        return dp[m][k];
    }
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;
        vector<int> a(slices.begin(), slices.end() - 1);
        vector<int> b(slices.begin() + 1, slices.end());
        return max(pickMax(a, k), pickMax(b, k));
    }
};
