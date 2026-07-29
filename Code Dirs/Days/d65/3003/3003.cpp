// Link: https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N*26) amortized via memoization, SC: O(N*26)
// Approach: DFS(i, mask, changeUsed) = max partitions from position i given the current
// (incomplete) segment already contains letter-set mask. At each step either extend the segment
// with s[i] (or start a new one if that would exceed k distinct letters), or — if the single
// allowed change hasn't been used — try replacing s[i] with every possible letter and take the
// best. Once changeUsed is true the "try all 26 letters" branch is gone, so the reachable
// (position, mask) state space collapses to O(26N) despite the branching factor at the moment
// the change is spent.
class Solution {
public:
    string str;
    int K;
    unordered_map<long long, int> memo;

    int popcount(int m) { return __builtin_popcount(m); }

    int dfs(int i, int mask, bool used) {
        int n = str.size();
        if (i == n) return mask != 0 ? 1 : 0;
        long long key = ((long long)i * 2 + (used ? 1 : 0)) * (1 << 27) + mask;
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int result = 0;
        // option a: keep s[i] as is
        int newMask = mask | (1 << (str[i] - 'a'));
        if (popcount(newMask) <= K) {
            result = dfs(i+1, newMask, used);
        } else {
            result = 1 + dfs(i+1, 1 << (str[i] - 'a'), used);
        }

        // option b: use the single change here (only if not yet used)
        if (!used) {
            for (int c = 0; c < 26; c++) {
                int cm = mask | (1 << c);
                int cand;
                if (popcount(cm) <= K) cand = dfs(i+1, cm, true);
                else cand = 1 + dfs(i+1, 1 << c, true);
                result = max(result, cand);
            }
        }

        memo[key] = result;
        return result;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        str = s;
        K = k;
        memo.clear();
        return dfs(0, 0, false);
    }
};
