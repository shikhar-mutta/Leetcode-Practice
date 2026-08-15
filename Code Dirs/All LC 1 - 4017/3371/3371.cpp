// Link: https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long total = 0;
        unordered_map<int,int> freq;
        for (int x : nums) { total += x; freq[x]++; }

        int best = INT_MIN;
        bool found = false;
        for (int x : nums) {
            long long outlierVal = total - 2LL * x;
            if (outlierVal < -2000000000LL || outlierVal > 2000000000LL) continue;
            int ov = (int)outlierVal;
            if (ov == x) {
                if (freq[x] >= 2) { found = true; best = max(best, ov); }
            } else {
                if (freq.count(ov) && freq[ov] > 0) { found = true; best = max(best, ov); }
            }
        }
        return found ? best : 0;
    }
};
