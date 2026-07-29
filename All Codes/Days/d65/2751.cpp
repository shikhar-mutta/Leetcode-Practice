// Link: https://leetcode.com/problems/robot-collisions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: process robots left to right by position, keeping a stack of surviving
// right-moving robot indices. A left-moving robot collides with the stack top repeatedly
// (asteroid-collision style), each collision knocking 1 health off the smaller and destroying
// ties or the loser; stop when the left-mover dies or wins outright.
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) { return positions[a] < positions[b]; });

        vector<int> health = healths;
        vector<bool> alive(n, true);
        vector<int> stk; // indices of alive right-moving robots, in position order

        for (int idx : order) {
            if (directions[idx] == 'R') {
                stk.push_back(idx);
                continue;
            }
            // moving left, collide with stack top(s)
            bool destroyed = false;
            while (!stk.empty() && !destroyed) {
                int top = stk.back();
                if (health[top] < health[idx]) {
                    alive[top] = false;
                    stk.pop_back();
                    health[idx]--;
                } else if (health[top] > health[idx]) {
                    health[top]--;
                    destroyed = true;
                } else {
                    alive[top] = false;
                    stk.pop_back();
                    destroyed = true;
                }
            }
            if (!destroyed) {
                // survived all collisions, stays alive moving left forever
            } else {
                alive[idx] = false;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) if (alive[i]) ans.push_back(health[i]);
        return ans;
    }
};
