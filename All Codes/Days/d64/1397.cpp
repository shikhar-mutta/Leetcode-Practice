// Link: https://leetcode.com/problems/find-all-good-strings/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * m * 26)  m = |evil|  SC: O(n * m)
// Approach: build a KMP automaton for `evil` (failure function + explicit
// transition table over 26 letters). Then countGood(bound) = number of
// length-n strings <= bound (digit-DP with a tight-bound flag) whose
// KMP-automaton state never reaches m (i.e. never fully matches evil).
// Answer = countGood(s2) - countGood(s1) + (s1 itself is good ? 1 : 0),
// all mod 1e9+7.
class Solution {
    string evil;
    int m;
    vector<int> fail;
    vector<vector<int>> trans; // trans[state][c] -> next state

    void buildAutomaton() {
        m = evil.size();
        fail.assign(m, 0);
        for (int i = 1; i < m; i++) {
            int j = fail[i - 1];
            while (j > 0 && evil[i] != evil[j]) j = fail[j - 1];
            if (evil[i] == evil[j]) j++;
            fail[i] = j;
        }
        trans.assign(m, vector<int>(26, 0));
        for (int state = 0; state < m; state++) {
            for (int c = 0; c < 26; c++) {
                char ch = 'a' + c;
                if (ch == evil[state]) {
                    trans[state][c] = state + 1;
                } else {
                    int j = state;
                    while (j > 0 && ch != evil[j]) j = fail[j - 1];
                    if (ch == evil[j]) j++;
                    trans[state][c] = j;
                }
            }
        }
    }

    long long countGood(int n, const string& bound) {
        const long long MOD = 1e9 + 7;
        vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(m, vector<long long>(2, -1)));
        function<long long(int,int,int)> dp = [&](int pos, int state, int tight) -> long long {
            if (state == m) return 0;
            if (pos == n) return 1;
            if (memo[pos][state][tight] != -1) return memo[pos][state][tight];
            int limit = tight ? (bound[pos] - 'a') : 25;
            long long total = 0;
            for (int c = 0; c <= limit; c++) {
                int ns = trans[state][c];
                if (ns == m) continue;
                total = (total + dp(pos + 1, ns, tight && (c == limit))) % MOD;
            }
            memo[pos][state][tight] = total;
            return total;
        };
        return dp(0, 0, 1);
    }

    bool isGood(const string& s) {
        int state = 0;
        for (char c : s) {
            state = trans[state][c - 'a'];
            if (state == m) return false;
        }
        return true;
    }
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        this->evil = evil;
        buildAutomaton();
        const long long MOD = 1e9 + 7;
        long long ans = (countGood(n, s2) - countGood(n, s1) + (isGood(s1) ? 1 : 0) + MOD) % MOD;
        return (int)ans;
    }
};
