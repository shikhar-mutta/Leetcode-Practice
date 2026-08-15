// Link: https://leetcode.com/problems/maximum-gap/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: bucket sort (pigeonhole) — with n numbers spanning [min,max], the answer is at least
// ceil((max-min)/(n-1)), so bucket width = that gives >= n-1 buckets; max gap must span between buckets,
// so only track each bucket's min/max and compare across consecutive non-empty buckets
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        if (lo == hi) return 0;
        int bucketSize = max(1, (hi - lo) / (n - 1));
        int bucketCount = (hi - lo) / bucketSize + 1;
        vector<int> bMin(bucketCount, INT_MAX), bMax(bucketCount, INT_MIN);
        for (int x : nums) {
            int idx = (x - lo) / bucketSize;
            bMin[idx] = min(bMin[idx], x);
            bMax[idx] = max(bMax[idx], x);
        }
        int best = 0, prevMax = lo;
        for (int i = 0; i < bucketCount; i++) {
            if (bMin[i] == INT_MAX) continue;
            best = max(best, bMin[i] - prevMax);
            prevMax = bMax[i];
        }
        return best;
    }
};
