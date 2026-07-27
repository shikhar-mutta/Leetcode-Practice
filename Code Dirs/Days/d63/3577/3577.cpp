// Link: https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: computer 0 unlocks first; any other computer j can be
// unlocked once SOME already-unlocked computer has smaller complexity,
// and computer 0 always qualifies for that as long as every other
// computer's complexity is strictly greater than complexity[0] — in that
// case every one of the remaining n-1 computers can be unlocked in any
// order at any time, giving (n-1)! valid permutations. If any other
// computer's complexity is <= complexity[0], it can never be unlocked.
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        const long long MOD = 1e9 + 7;
        int n = complexity.size();
        for (int i = 1; i < n; i++) if (complexity[i] <= complexity[0]) return 0;

        long long ans = 1;
        for (int i = 2; i < n; i++) ans = (ans * i) % MOD;
        return (int)ans;
    }
};
