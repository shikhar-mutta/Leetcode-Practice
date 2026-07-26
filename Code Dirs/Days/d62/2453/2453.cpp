// Link: https://leetcode.com/problems/destroy-sequential-targets/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n)
// Approach: firing at x destroys every target whose value is congruent
// to x mod space, so group targets by num % space, tracking each group's
// size and its smallest value. The best group is the largest one
// (ties broken by the smallest value, per the problem's tie-break rule).
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        unordered_map<int, pair<int, int>> groups;

        for (int num : nums) {
            int rm = num % space;
            auto it = groups.find(rm);
            if (it == groups.end()) {
                groups[rm] = {1, num};
            } else {
                it->second.first++; // one more target
                it->second.second =
                    min(it->second.second, num); // keep smallest seed
            }
        }

        pair<int, int> best{0, INT_MAX}; // {count, minSeed}
        for (const auto& [rm, res] : groups) {
            auto [cnt, mn] = res;
            if (cnt > best.first || // strictly bigger group -> take it
                (cnt == best.first &&
                 mn < best.second)) { // tie -> keep smaller seed
                best = {cnt, mn};
            }
        }
        return best.second;
    }
};
