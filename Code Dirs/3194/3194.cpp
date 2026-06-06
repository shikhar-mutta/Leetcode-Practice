// Link: https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n/2) ~ O(nlogn). SC: O(1).
    double minimumAverage(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double minAvg = INT_MAX;
        for (int i = 0; i < n / 2; i++)
            minAvg = min(minAvg, (nums[i] + nums[n - 1 - i]) / 2.0);

        return minAvg;
    }
};
