// Link: https://leetcode.com/problems/minimum-number-of-groups-to-create-a-valid-assignment/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + u*mn), where u is the number of distinct values and mn is the
// minimum frequency among them
// SC: O(u) for the frequency map
// Approach: count frequencies, then try each possible smaller group size x
// from mn down to 1. A frequency f is valid if it can be split into groups of
// size x or x+1; using ceil(f/(x+1)) groups gives the minimum groups for that
// x. The first valid x gives the overall minimum group count.
class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int x : nums)
            freq[x]++;

        int mn = INT_MAX;
        for (auto& [_, f] : freq)
            mn = min(mn, f);

        for (int x = mn; x >= 1; x--) {

            int groups = 0;
            bool ok = true;

            for (auto& [_, f] : freq) {

                int g = (f + x) / (x + 1); // ceil(f / (x+1))

                if (g * x > f) {
                    ok = false;
                    break;
                }

                groups += g;
            }

            if (ok)
                return groups;
        }

        return nums.size();
    }
};
