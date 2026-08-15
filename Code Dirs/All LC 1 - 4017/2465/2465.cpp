// Link: https://leetcode.com/problems/number-of-distinct-averages/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        set<double> avgs;
        for (int i = 0; i < n / 2; i++)
            avgs.insert((nums[i] + nums[n-1-i]) / 2.0);
        return avgs.size();
    }
};
