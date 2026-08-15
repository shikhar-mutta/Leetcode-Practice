// Link: https://leetcode.com/problems/find-the-sum-of-subsequence-powers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long f(vector<int>& nums, int k, long long d) {
        int n = nums.size();
        // boundary[i] = number of elements nums[0..i'] with nums[i']<=nums[i]-d (i.e count, exclusive upper index)
        vector<int> boundary(n);
        int p = 0;
        for (int i = 0; i < n; i++) {
            while (p < n && (long long)nums[p] <= nums[i] - d) p++;
            boundary[i] = p; // number of valid predecessors (indices 0..p-1)
        }
        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> prefix(n + 1, vector<long long>(k + 1, 0)); // prefix[i][j] = sum dp[0..i-1][j]
        for (int i = 0; i < n; i++) {
            dp[i][1] = 1;
            for (int j = 2; j <= k; j++) {
                dp[i][j] = prefix[boundary[i]][j-1] % MOD;
            }
            for (int j = 1; j <= k; j++) prefix[i+1][j] = (prefix[i][j] + dp[i][j]) % MOD;
        }
        long long total = 0;
        for (int i = 0; i < n; i++) total = (total + dp[i][k]) % MOD;
        return total;
    }

    int sumOfPowers(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<long long> diffSet;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                diffSet.insert(nums[i] - nums[j]);
        vector<long long> diffs(diffSet.begin(), diffSet.end());

        long long ans = 0;
        long long prev = 0;
        for (long long c : diffs) {
            long long fc = f(nums, k, c);
            long long weight = ((c - prev) % MOD + MOD) % MOD;
            ans = (ans + fc * weight) % MOD;
            prev = c;
        }
        return (int)ans;
    }
};
