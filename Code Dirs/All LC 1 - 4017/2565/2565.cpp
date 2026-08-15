// Link: https://leetcode.com/problems/subsequence-with-the-minimum-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.size(), m = t.size();
        const int INF = n + 1;

        // matchFromStart[i] = min chars of s (from start) needed to match t[0..i) as subsequence
        vector<int> matchFromStart(m + 1, INF);
        matchFromStart[0] = 0;
        {
            int sp = 0;
            for (int tp = 0; tp < m; tp++) {
                while (sp < n && s[sp] != t[tp]) sp++;
                if (sp < n) { sp++; matchFromStart[tp+1] = sp; }
                else break;
            }
        }

        // matchFromEnd[i] = min chars of s (from end) needed to match t[i..m) as subsequence
        vector<int> matchFromEnd(m + 1, INF);
        matchFromEnd[m] = 0;
        {
            int sp = n - 1;
            for (int tp = m - 1; tp >= 0; tp--) {
                while (sp >= 0 && s[sp] != t[tp]) sp--;
                if (sp >= 0) { matchFromEnd[tp] = n - sp; sp--; }
                else break;
            }
        }

        int best = m; // remove all of t
        int j = 0;
        for (int i = 0; i <= m; i++) {
            if (matchFromStart[i] == INF) break;
            if (j < i) j = i;
            while (j <= m && (matchFromEnd[j] == INF || matchFromStart[i] + matchFromEnd[j] > n)) j++;
            if (j <= m) best = min(best, j - i);
        }
        return best;
    }
};
