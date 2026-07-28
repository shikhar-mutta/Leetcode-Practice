// Link: https://leetcode.com/problems/stamping-the-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * (n-m))  n=|target|, m=|stamp|  SC: O(n)
// Approach: reverse simulation. Repeatedly scan for a window in target
// that could have been the last stamp applied — every character either
// already matches stamp or is '?' (already turned into stamp by an
// earlier reverse move), with at least one real (non-'?') match so we
// make progress. Turn that whole window into '?', record its start
// index, and repeat until everything is '?' (success) or no window
// qualifies (impossible). Moves are recorded in reverse stamping order,
// so the final answer is reversed.
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int m = stamp.size(), n = target.size();
        vector<int> moves;
        vector<bool> done(n, false);
        int turned = 0;

        while (turned < n) {
            bool progress = false;
            for (int i = 0; i + m <= n; i++) {
                if (done[i]) continue;
                bool canStamp = true, hasReal = false;
                for (int j = 0; j < m; j++) {
                    if (target[i + j] == '?') continue;
                    if (target[i + j] != stamp[j]) { canStamp = false; break; }
                    hasReal = true;
                }
                if (!canStamp || !hasReal) continue;
                for (int j = 0; j < m; j++) {
                    if (target[i + j] != '?') { target[i + j] = '?'; turned++; }
                }
                done[i] = true;
                moves.push_back(i);
                progress = true;
            }
            if (!progress) break;
        }
        if (turned != n) return {};
        reverse(moves.begin(), moves.end());
        return moves;
    }
};
