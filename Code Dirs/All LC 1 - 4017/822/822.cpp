// Link: https://leetcode.com/problems/card-flipping-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: a number can never be "good" if it appears on both faces of the same card (any flip still shows it). Collect all such "bad" numbers; the answer is the smallest number among all faces not in the bad set.
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        unordered_set<int> bad;
        for (size_t i = 0; i < fronts.size(); i++) if (fronts[i] == backs[i]) bad.insert(fronts[i]);
        int best = INT_MAX;
        for (int x : fronts) if (!bad.count(x)) best = min(best, x);
        for (int x : backs) if (!bad.count(x)) best = min(best, x);
        return best == INT_MAX ? 0 : best;
    }
};
