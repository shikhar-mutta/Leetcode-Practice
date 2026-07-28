// Link: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> C;

    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;
        vector<int> left, right;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        long long l = solve(left), r = solve(right);
        return (((C[n-1][left.size()] * l) % MOD) * r) % MOD;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        C.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            C[i][0] = 1;
            for (int j = 1; j <= i; j++)
                C[i][j] = (C[i-1][j-1] + (j <= i-1 ? C[i-1][j] : 0)) % MOD;
        }
        long long total = solve(nums);
        return (int)((total - 1 + MOD) % MOD);
    }
};
