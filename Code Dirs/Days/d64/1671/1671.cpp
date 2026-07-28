// Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> inc(n, 1), dec(n, 1);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++)
                if (nums[j] < nums[i]) inc[i] = max(inc[i], inc[j] + 1);
        for (int i = n - 1; i >= 0; i--)
            for (int j = n - 1; j > i; j--)
                if (nums[j] < nums[i]) dec[i] = max(dec[i], dec[j] + 1);
        int best = 0;
        for (int i = 0; i < n; i++)
            if (inc[i] > 1 && dec[i] > 1)
                best = max(best, inc[i] + dec[i] - 1);
        return n - best;
    }
};
