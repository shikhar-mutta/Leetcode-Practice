// Link: https://leetcode.com/problems/find-all-good-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    vector<int> computeFail(string& evil) {
        int m = evil.size();
        vector<int> fail(m, 0);
        int k = 0;
        for (int i = 1; i < m; i++) {
            while (k > 0 && evil[i] != evil[k]) k = fail[k-1];
            if (evil[i] == evil[k]) k++;
            fail[i] = k;
        }
        return fail;
    }

    vector<vector<int>> buildAutomaton(string& evil) {
        int m = evil.size();
        vector<int> fail = computeFail(evil);
        vector<vector<int>> nxt(m, vector<int>(26, 0));
        for (int c = 0; c < 26; c++) {
            nxt[0][c] = (c == evil[0] - 'a') ? 1 : 0;
        }
        for (int state = 1; state < m; state++) {
            for (int c = 0; c < 26; c++) {
                if (c == evil[state] - 'a') nxt[state][c] = state + 1;
                else nxt[state][c] = nxt[fail[state-1]][c];
            }
        }
        return nxt;
    }

    int n, m;
    string s1, s2, evil;
    vector<vector<int>> automaton;
    vector<vector<vector<vector<long long>>>> memo;

    long long dfs(int pos, int state, bool tightLow, bool tightHigh) {
        if (state == m) return 0;
        if (pos == n) return 1;
        if (memo[pos][state][tightLow][tightHigh] != -1) return memo[pos][state][tightLow][tightHigh];

        int lo = tightLow ? (s1[pos] - 'a') : 0;
        int hi = tightHigh ? (s2[pos] - 'a') : 25;

        long long sum = 0;
        for (int c = lo; c <= hi; c++) {
            int nstate = automaton[state][c];
            if (nstate == m) continue;
            sum = (sum + dfs(pos + 1, nstate, tightLow && c == lo, tightHigh && c == hi)) % MOD;
        }
        memo[pos][state][tightLow][tightHigh] = sum;
        return sum;
    }

    int findGoodStrings(int n, string s1, string s2, string evil) {
        this->n = n; this->s1 = s1; this->s2 = s2; this->evil = evil;
        m = evil.size();
        automaton = buildAutomaton(evil);
        memo.assign(n + 1, vector<vector<vector<long long>>>(m, vector<vector<long long>>(2, vector<long long>(2, -1))));
        return (int)dfs(0, 0, true, true);
    }
};
