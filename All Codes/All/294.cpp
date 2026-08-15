// Link: https://leetcode.com/problems/flip-game-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 2^n) worst case, memoized on state string  SC: O(2^n) memo
// Approach: current player wins if any move leads to a state where the
// opponent cannot win; memoize by string state
class Solution {
    unordered_map<string, bool> memo;

    bool win(string s) {
        auto it = memo.find(s);
        if (it != memo.end()) return it->second;
        for (int i = 0; i + 1 < (int)s.size(); i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                s[i] = '-'; s[i + 1] = '-';
                bool opponentWins = win(s);
                s[i] = '+'; s[i + 1] = '+';
                if (!opponentWins) return memo[s] = true;
            }
        }
        return memo[s] = false;
    }

public:
    bool canWin(string currentState) {
        return win(currentState);
    }
};
