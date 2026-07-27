// Link: https://leetcode.com/problems/closest-equal-element-queries/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q) SC: O(n)
// Approach: group indices by value. For each group, the nearest equal
// element (circularly) to any index is always one of its two neighbors
// in the sorted-by-index circular list, so walk each group's consecutive
// pairs (wrapping) and update both endpoints' best circular distance.
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[nums[i]].push_back(i);

        vector<int> best(n, -1);
        for (auto& [val, list] : groups) {
            int s = list.size();
            if (s < 2) continue;
            for (int k = 0; k < s; k++) {
                int a = list[k], b = list[(k + 1) % s];
                int diff = (b - a + n) % n;
                int dist = min(diff, n - diff);
                best[a] = (best[a] == -1) ? dist : min(best[a], dist);
                best[b] = (best[b] == -1) ? dist : min(best[b], dist);
            }
        }

        vector<int> ans;
        for (int q : queries) ans.push_back(best[q]);
        return ans;
    }
};
