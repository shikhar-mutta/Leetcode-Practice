// Link: https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> conv(n);
        long long maxSoFar = 0;
        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, (long long)nums[i]);
            conv[i] = nums[i] + maxSoFar;
        }
        vector<long long> ans(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += conv[i];
            ans[i] = sum;
        }
        return ans;
    }
};
