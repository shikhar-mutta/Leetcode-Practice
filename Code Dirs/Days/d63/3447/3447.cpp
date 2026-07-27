// Link: https://leetcode.com/problems/assign-elements-to-groups-with-constraints/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(maxGroup * log(maxGroup)) SC: O(maxGroup)
// Approach: sieve-style. For each distinct element value (in increasing
// index order, so earlier indices win ties), mark every multiple of that
// value up to the max group value with this element's index, but only if
// not already marked by an earlier (smaller-index) element. Answer for
// each group is then a direct lookup.
class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int maxG = *max_element(groups.begin(), groups.end());
        vector<int> best(maxG + 1, -1);
        unordered_set<int> seen;

        for (int idx = 0; idx < (int)elements.size(); idx++) {
            int v = elements[idx];
            if (seen.count(v)) continue;
            seen.insert(v);
            if (v > maxG) continue;
            for (int m = v; m <= maxG; m += v) {
                if (best[m] == -1) best[m] = idx;
            }
        }

        vector<int> ans(groups.size());
        for (int i = 0; i < (int)groups.size(); i++) ans[i] = best[groups[i]];
        return ans;
    }
};
