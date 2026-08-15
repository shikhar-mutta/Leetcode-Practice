// Link: https://leetcode.com/problems/count-the-number-of-winning-sequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 0=F,1=W,2=E; beats(a,b): F beats E, W beats F, E beats W
    bool beats(int a, int b) {
        return (a == 0 && b == 2) || (a == 1 && b == 0) || (a == 2 && b == 1);
    }

    int countWinningSequences(string s) {
        const long long MOD = 1000000007;
        int n = s.size();
        int offset = n;
        int size = 2 * n + 1;

        auto charToMove = [](char c) -> int {
            if (c == 'F') return 0;
            if (c == 'W') return 1;
            return 2;
        };

        // dp[diff+offset][lastMove], lastMove in 0..2, or 3 = "no previous move"
        vector<vector<long long>> dp(size, vector<long long>(4, 0));
        dp[offset][3] = 1; // start: diff=0, no last move

        for (int i = 0; i < n; i++) {
            int aliceMove = charToMove(s[i]);
            vector<vector<long long>> ndp(size, vector<long long>(4, 0));
            for (int diff = 0; diff < size; diff++) {
                for (int last = 0; last < 4; last++) {
                    if (dp[diff][last] == 0) continue;
                    long long c = dp[diff][last];
                    for (int bobMove = 0; bobMove < 3; bobMove++) {
                        if (bobMove == last) continue;
                        int delta = 0;
                        if (beats(bobMove, aliceMove)) delta = 1;
                        else if (beats(aliceMove, bobMove)) delta = -1;
                        int newDiff = diff + delta;
                        if (newDiff < 0 || newDiff >= size) continue;
                        ndp[newDiff][bobMove] = (ndp[newDiff][bobMove] + c) % MOD;
                    }
                }
            }
            dp = move(ndp);
        }

        long long ans = 0;
        for (int diff = offset + 1; diff < size; diff++) {
            for (int last = 0; last < 4; last++) {
                ans = (ans + dp[diff][last]) % MOD;
            }
        }
        return (int)ans;
    }
};
