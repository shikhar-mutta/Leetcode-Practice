// Link: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<long long> sorted(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end());

        set<long long> candidates;
        for (long long x : nums) {
            candidates.insert(x);
            candidates.insert(x - k);
            candidates.insert(x + k);
        }

        int best = 0;
        for (long long v : candidates) {
            int already = upper_bound(sorted.begin(), sorted.end(), v) - lower_bound(sorted.begin(), sorted.end(), v);
            int lo = lower_bound(sorted.begin(), sorted.end(), v - k) - sorted.begin();
            int hi = upper_bound(sorted.begin(), sorted.end(), v + k) - sorted.begin();
            int inRange = hi - lo;
            int freq = already + min(numOperations, inRange - already);
            best = max(best, freq);
        }
        return best;
    }
};
