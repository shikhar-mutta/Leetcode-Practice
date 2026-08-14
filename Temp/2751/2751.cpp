// Link: https://leetcode.com/problems/robot-collisions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) { return positions[a] < positions[b]; });

        vector<bool> alive(n, true);
        vector<int> stk; // indices of right-moving alive robots

        for (int idx : order) {
            if (directions[idx] == 'R') {
                stk.push_back(idx);
            } else {
                bool curAlive = true;
                while (curAlive && !stk.empty()) {
                    int top = stk.back();
                    if (healths[top] > healths[idx]) {
                        healths[top]--;
                        alive[idx] = false;
                        curAlive = false;
                    } else if (healths[top] < healths[idx]) {
                        healths[idx]--;
                        alive[top] = false;
                        stk.pop_back();
                    } else {
                        alive[top] = false;
                        alive[idx] = false;
                        stk.pop_back();
                        curAlive = false;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) if (alive[i]) ans.push_back(healths[i]);
        return ans;
    }
};
