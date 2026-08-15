// Link: https://leetcode.com/problems/zuma-game/description/

#include <bits/stdc++.h>
using namespace std;

// TC: exponential worst case, pruned by memoization  SC: O(states)
// Approach: backtrack - try inserting each distinct hand ball at each
// position in the board, remove resulting runs of >=3, recurse with
// remaining hand; memoize on (board, sorted hand) to avoid repeated work
class Solution {
    unordered_map<string, int> memo;

    string removeRuns(string b) {
        bool changed = true;
        while (changed) {
            changed = false;
            int n = b.size();
            int i = 0;
            while (i < n) {
                int j = i;
                while (j < n && b[j] == b[i]) j++;
                if (j - i >= 3) {
                    b = b.substr(0, i) + b.substr(j);
                    changed = true;
                    break;
                }
                i = j;
            }
        }
        return b;
    }

    int solve(string board, string hand) {
        if (board.empty()) return 0;
        sort(hand.begin(), hand.end());
        string key = board + "#" + hand;
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int best = INT_MAX;
        for (int i = 0; i < (int)hand.size(); i++) {
            if (i > 0 && hand[i] == hand[i-1]) continue;
            char ball = hand[i];
            string nextHand = hand.substr(0, i) + hand.substr(i + 1);
            for (int pos = 0; pos <= (int)board.size(); pos++) {
                if (pos > 0 && board[pos-1] == ball) continue; // equivalent insert positions in a run
                string nextBoard = board.substr(0, pos) + ball + board.substr(pos);
                string cleared = removeRuns(nextBoard);
                int res = solve(cleared, nextHand);
                if (res != INT_MAX) best = min(best, res + 1);
            }
        }
        memo[key] = best;
        return best;
    }

public:
    int findMinStep(string board, string hand) {
        int res = solve(board, hand);
        return res == INT_MAX ? -1 : res;
    }
};
