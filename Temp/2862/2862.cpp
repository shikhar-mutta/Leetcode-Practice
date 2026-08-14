// Link: https://leetcode.com/problems/maximum-element-sum-of-a-complete-subset-of-indices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int s = 1; s <= n; s++) {
            int sf = s;
            for (int p = 2; (long long)p * p <= sf; p++) {
                while (sf % (p * p) == 0) sf /= (p * p);
            }
            if (sf != s) continue; // s must itself be squarefree to be a base
            long long sum = 0;
            for (long long k = 1; s * k * k <= n; k++) {
                sum += nums[s * k * k - 1];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};
