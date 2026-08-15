// Link: https://leetcode.com/problems/closest-subsequence-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void genSums(vector<int>& arr, vector<long long>& sums) {
        int n = arr.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            long long s = 0;
            for (int i = 0; i < n; i++) if (mask & (1 << i)) s += arr[i];
            sums.push_back(s);
        }
        sort(sums.begin(), sums.end());
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int half = n / 2;
        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());

        vector<long long> leftSums, rightSums;
        genSums(left, leftSums);
        genSums(right, rightSums);

        long long best = LLONG_MAX;
        for (long long ls : leftSums) {
            long long target = goal - ls;
            auto it = lower_bound(rightSums.begin(), rightSums.end(), target);
            if (it != rightSums.end()) best = min(best, llabs(ls + *it - goal));
            if (it != rightSums.begin()) {
                auto it2 = prev(it);
                best = min(best, llabs(ls + *it2 - goal));
            }
        }
        return (int)best;
    }
};
