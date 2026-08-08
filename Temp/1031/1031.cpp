// Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        return max(best(prefix, firstLen, secondLen), best(prefix, secondLen, firstLen));
    }

private:
    int best(vector<int>& prefix, int aLen, int bLen) {
        int n = prefix.size() - 1;
        int maxA = 0, res = 0;
        for (int i = aLen + bLen; i <= n; i++) {
            maxA = max(maxA, prefix[i - bLen] - prefix[i - bLen - aLen]);
            int bSum = prefix[i] - prefix[i - bLen];
            res = max(res, maxA + bSum);
        }
        return res;
    }
};
