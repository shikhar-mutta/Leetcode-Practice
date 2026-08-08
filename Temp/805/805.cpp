// Link: https://leetcode.com/problems/split-array-with-same-average/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(2^(n/2) * n) SC: O(2^(n/2))
// Approach: meet-in-the-middle; split nums into two halves, enumerate all subset sums bucketed by subset size for each half. For each valid subset size k (1..n-1) where k*total is divisible by n, look for a left-subset sum + right-subset sum combination hitting the target k*total/n.
class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return false;
        int total = accumulate(nums.begin(), nums.end(), 0);
        int m = n / 2, rm = n - m;

        vector<vector<int>> leftSums(m+1), rightSums(rm+1);
        for (int mask = 0; mask < (1 << m); mask++) {
            int cnt = __builtin_popcount(mask), sum = 0;
            for (int i = 0; i < m; i++) if (mask & (1 << i)) sum += nums[i];
            leftSums[cnt].push_back(sum);
        }
        for (int mask = 0; mask < (1 << rm); mask++) {
            int cnt = __builtin_popcount(mask), sum = 0;
            for (int i = 0; i < rm; i++) if (mask & (1 << i)) sum += nums[m+i];
            rightSums[cnt].push_back(sum);
        }
        for (auto& v : rightSums) sort(v.begin(), v.end());

        for (int k = 1; k < n; k++) {
            if ((long long)k * total % n != 0) continue;
            long long target = (long long)k * total / n;
            for (int lk = max(0, k - rm); lk <= min(k, m); lk++) {
                int rk = k - lk;
                for (int ls : leftSums[lk]) {
                    long long need = target - ls;
                    if (need >= 0 && need <= INT_MAX &&
                        binary_search(rightSums[rk].begin(), rightSums[rk].end(), (int)need)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
