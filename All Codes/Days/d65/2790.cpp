// Link: https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(1)
// Approach: sort ascending, greedily accumulate a running total of available usages; whenever
// the total can fill group k+1 (size k+1), consume that much and increment the group count.
class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        long long total = 0;
        int k = 0;
        for (int x : usageLimits) {
            total += x;
            if (total >= k + 1) { total -= (k + 1); k++; }
        }
        return k;
    }
};
