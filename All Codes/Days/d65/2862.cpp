// Link: https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N sqrt(N)), SC: O(N)
// Approach: index i*j^2 for varying j all share the same "squarefree core" (i with all square
// factors removed). A complete subset corresponds exactly to indices sharing a squarefree core
// {core*1^2, core*2^2, ...}, so group indices by their squarefree core and sum, taking the max.
class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, long long> sums;
        for (int i = 1; i <= n; i++) {
            int core = i;
            for (int p = 2; (long long)p * p <= core; p++) {
                while (core % (p*p) == 0) core /= (p*p);
            }
            sums[core] += nums[i-1];
        }
        long long ans = 0;
        for (auto& [k, v] : sums) ans = max(ans, v);
        return ans;
    }
};
