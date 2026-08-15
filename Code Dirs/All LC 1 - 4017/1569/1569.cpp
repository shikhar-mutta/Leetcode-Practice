// Link: https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> binom;

    void buildBinom(int n) {
        binom.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) {
            binom[i][0] = 1;
            for (int j = 1; j <= i; j++) {
                binom[i][j] = (binom[i-1][j-1] + (j <= i-1 ? binom[i-1][j] : 0)) % MOD;
            }
        }
    }

    long long count(vector<int>& arr) {
        if (arr.size() <= 1) return 1;
        int root = arr[0];
        vector<int> left, right;
        for (int i = 1; i < (int)arr.size(); i++) {
            if (arr[i] < root) left.push_back(arr[i]);
            else right.push_back(arr[i]);
        }
        long long leftWays = count(left);
        long long rightWays = count(right);
        long long ways = binom[left.size() + right.size()][left.size()];
        return (((ways * leftWays) % MOD) * rightWays) % MOD;
    }

    int numOfWays(vector<int>& nums) {
        buildBinom(nums.size());
        long long total = count(nums);
        return (int)((total - 1 + MOD) % MOD);
    }
};
