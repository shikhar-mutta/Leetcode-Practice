// Link: https://leetcode.com/problems/bulb-switcher-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) (bounded enumeration) SC: O(1)
// Approach: only parity of how many times each of the 4 buttons is pressed matters, and the resulting pattern only depends on min(n,6) bulbs (period repeats). Enumerate all 16 combinations of button parities; a combination is feasible if its total presses has the same parity as `presses` and is <= presses. Collect distinct resulting states.
class Solution {
public:
    int flipLights(int n, int presses) {
        n = min(n, 6);
        set<vector<int>> states;
        for (int mask = 0; mask < 16; mask++) {
            int b0 = mask&1, b1 = (mask>>1)&1, b2 = (mask>>2)&1, b3 = (mask>>3)&1;
            int total = b0+b1+b2+b3;
            if (total > presses) continue;
            if ((presses - total) % 2 != 0) continue;
            vector<int> state(n, 1);
            for (int i = 0; i < n; i++) {
                int idx = i+1;
                if (b0) state[i] ^= 1;
                if (b1 && idx % 2 == 0) state[i] ^= 1;
                if (b2 && idx % 2 == 1) state[i] ^= 1;
                if (b3 && idx % 3 == 1) state[i] ^= 1;
            }
            states.insert(state);
        }
        return states.size();
    }
};
