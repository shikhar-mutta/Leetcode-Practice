// Link: https://leetcode.com/problems/flip-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n) for output
// Approach: scan for every adjacent "++" pair, flip it to "--" for that result
class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> res;
        for (int i = 0; i + 1 < (int)currentState.size(); i++) {
            if (currentState[i] == '+' && currentState[i + 1] == '+') {
                string next = currentState;
                next[i] = '-';
                next[i + 1] = '-';
                res.push_back(next);
            }
        }
        return res;
    }
};
