// Link: https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        sort(usageLimits.begin(), usageLimits.end());
        long long sum = 0;
        int k = 0;
        for (int x : usageLimits) {
            sum += x;
            if (sum >= (long long)(k+1) * (k+2) / 2) k++;
        }
        return k;
    }
};
