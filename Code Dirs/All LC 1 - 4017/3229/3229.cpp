// Link: https://leetcode.com/problems/minimum-operations-to-make-array-equal-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        long long ans = 0;
        long long prevPos = 0, prevNeg = 0;
        for (int i = 0; i < n; i++) {
            long long d = (long long)target[i] - nums[i];
            long long pos = max(0LL, d);
            long long neg = max(0LL, -d);
            ans += max(0LL, pos - prevPos);
            ans += max(0LL, neg - prevNeg);
            prevPos = pos;
            prevNeg = neg;
        }
        return ans;
    }
};
