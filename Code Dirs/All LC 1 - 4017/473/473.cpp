// Link: https://leetcode.com/problems/matchsticks-to-square/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(4^n)  SC: O(n)
// Approach: backtrack sorted (desc) sticks into 4 sides, pruning by side
// length and skipping duplicate empty-bucket assignments
class Solution {
    bool backtrack(vector<int>& sticks, vector<int>& sides, int idx, int target) {
        if (idx == (int)sticks.size()) return true;
        for (int i = 0; i < 4; i++) {
            if (sides[i] + sticks[idx] > target) continue;
            if (i > 0 && sides[i] == sides[i-1]) continue;
            sides[i] += sticks[idx];
            if (backtrack(sticks, sides, idx + 1, target)) return true;
            sides[i] -= sticks[idx];
        }
        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> sides(4, 0);
        return backtrack(matchsticks, sides, 0, sum / 4);
    }
};
