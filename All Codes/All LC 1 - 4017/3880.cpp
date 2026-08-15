// Link: https://leetcode.com/problems/minimum-absolute-difference-between-two-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) + O(m) ~ O(nlogn). SC: O(n) + O(m) ~ O(n).
    int minAbsoluteDifference(vector<int> &nums)
    {
        unordered_map<int, vector<int>> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            freq[nums[i]].push_back(i);
        int ans = INT_MAX;
        vector<int> one(freq[1].begin(), freq[1].end()), two(freq[2].begin(), freq[2].end());
        if (one.empty() || two.empty())
            return -1;
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        int minDiff = INT_MAX;
        for (int i : one)
        {
            int preDist = INT_MAX;
            for (int j : two)
            {
                int dist = abs(i - j);
                if (dist < preDist)
                    preDist = dist;
                else
                    break;
            }
            minDiff = min(minDiff, preDist);
        }
        return minDiff;
    }
};
