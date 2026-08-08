// Link: https://leetcode.com/problems/employee-free-time/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: flatten all intervals across employees, sort by start, then merge; the gaps between consecutive merged intervals are the common free time.
class Solution {
public:
    vector<vector<int>> employeeFreeTime(vector<vector<vector<int>>>& schedule) {
        vector<vector<int>> all;
        for (auto& emp : schedule) for (auto& iv : emp) all.push_back(iv);
        sort(all.begin(), all.end());
        vector<vector<int>> merged;
        for (auto& iv : all) {
            if (!merged.empty() && iv[0] <= merged.back()[1]) {
                merged.back()[1] = max(merged.back()[1], iv[1]);
            } else {
                merged.push_back(iv);
            }
        }
        vector<vector<int>> res;
        for (size_t i = 1; i < merged.size(); i++) {
            if (merged[i][0] > merged[i-1][1]) res.push_back({merged[i-1][1], merged[i][0]});
        }
        return res;
    }
};
