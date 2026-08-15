// Link: https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double best = 1e18;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            best = min(best, (nums[i] + nums[j]) / 2.0);
        }
        return best;
    }
};
