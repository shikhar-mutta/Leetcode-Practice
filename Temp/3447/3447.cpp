// Link: https://leetcode.com/problems/assign-elements-to-groups-with-constraints/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int maxVal = *max_element(groups.begin(), groups.end());
        vector<int> best(maxVal + 1, -1);

        for (int i = 0; i < (int)elements.size(); i++) {
            int e = elements[i];
            if (e > maxVal) continue;
            if (best[e] != -1) continue; // an earlier (smaller index) same-value element already handled this and its multiples? not guaranteed, so check per multiple below
            for (long long m = e; m <= maxVal; m += e) {
                if (best[m] == -1) best[m] = i;
            }
        }

        vector<int> ans(groups.size());
        for (int i = 0; i < (int)groups.size(); i++) ans[i] = best[groups[i]];
        return ans;
    }
};
