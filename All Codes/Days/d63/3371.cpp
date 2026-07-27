// Link: https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: total = 2*sum(specials) + outlier, so for each value v treated
// as the "sum" element, the outlier candidate is total - 2*v. Check that
// candidate actually exists in the array (with a second occurrence if it
// equals v itself), and take the max valid candidate over all v.
class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        long long total = 0;
        unordered_map<int,int> freq;
        for (int x : nums) { total += x; freq[x]++; }

        int ans = INT_MIN;
        for (auto& [v, c] : freq) {
            long long cand = total - 2LL * v;
            if (cand < INT_MIN || cand > INT_MAX) continue;
            int candi = (int)cand;
            auto it = freq.find(candi);
            if (it == freq.end()) continue;
            if (candi == v) {
                if (c < 2) continue;
            }
            ans = max(ans, candi);
        }
        return ans;
    }
};
