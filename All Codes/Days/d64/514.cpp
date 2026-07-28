// Link: https://leetcode.com/problems/freedom-trail/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(|key| * |ring|^2)  SC: O(|ring|)
// Approach: precompute positions of each ring letter. DP over key
// characters: dp[pos] = min total cost to have spelled the current key
// prefix with the ring pointer at `pos`. For each key char, transition
// from every previous candidate position to every position holding the
// current char, cost = min rotation distance around the ring + 1 (press).
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < n; i++) pos[ring[i]].push_back(i);

        unordered_map<int, int> dp;
        dp[0] = 0;
        for (char c : key) {
            unordered_map<int, int> ndp;
            for (int np : pos[c]) {
                int best = INT_MAX;
                for (auto& [p, cost] : dp) {
                    int diff = abs(np - p);
                    int rot = min(diff, n - diff);
                    best = min(best, cost + rot + 1);
                }
                ndp[np] = best;
            }
            dp = ndp;
        }
        int ans = INT_MAX;
        for (auto& [p, cost] : dp) ans = min(ans, cost);
        return ans;
    }
};
