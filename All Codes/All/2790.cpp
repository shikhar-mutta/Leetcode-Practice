// Link: https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the length of the usageLimits, SC: O(n) where n is the length of the usageLimits
// Approach: We can use a greedy approach to find the maximum number of groups with increasing length. We will first sort the usageLimits in non-decreasing order. Then, we will iterate through the sorted usageLimits and for each limit, we will check if we can form a new group with the current limit. If we can form a new group, we will increment the number of groups and update the total usage. Finally, we will return the number of groups formed.
class Solution
{
public:
    int maxIncreasingGroups(vector<int> &usageLimits)
    {
        const int n = usageLimits.size();
        vector<int> cnt(n + 1);
        for (const int limit : usageLimits)
            ++cnt[min(n, limit)];
        long long total = 0, numGroups = 0;
        for (int limit = 1; limit <= n; ++limit)
        {
            for (int rem = cnt[limit]; rem > 0; --rem)
            {
                total += limit;
                const auto triTotal = (numGroups + 1) * (numGroups + 2) / 2;
                numGroups += (total >= triTotal);
            }
        }
        return numGroups;
    }
};