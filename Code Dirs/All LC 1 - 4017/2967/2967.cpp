// Link: https://leetcode.com/problems/minimum-cost-to-make-array-equalindromic/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(long long x) {
        string s = to_string(x);
        string r = s;
        reverse(r.begin(), r.end());
        return s == r;
    }

    long long cost(vector<int>& nums, long long x) {
        long long c = 0;
        for (int v : nums) c += abs((long long)v - x);
        return c;
    }

    long long minimumCost(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long median = nums[n / 2];

        long long lowCandidate = -1, highCandidate = -1;
        for (long long d = 0; median - d >= 0; d++) {
            if (isPalindrome(median - d)) { lowCandidate = median - d; break; }
        }
        for (long long d = 0; ; d++) {
            if (isPalindrome(median + d)) { highCandidate = median + d; break; }
        }
        long long best = LLONG_MAX;
        if (lowCandidate != -1) best = min(best, cost(nums, lowCandidate));
        if (highCandidate != -1) best = min(best, cost(nums, highCandidate));
        return best;
    }
};
