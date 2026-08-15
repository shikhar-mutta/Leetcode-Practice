// Link: https://leetcode.com/problems/maximum-frequency-of-an-element-after-performing-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        int n = sorted.size();

        set<int> candidates;
        for (int x : nums) {
            candidates.insert(x);
            candidates.insert(x - k);
            candidates.insert(x + k);
        }
        int best = 0;
        for (int v : candidates) {
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
