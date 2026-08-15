// Link: https://leetcode.com/problems/substring-with-largest-variance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        set<char> chars(s.begin(), s.end());
        const int NEG_INF = INT_MIN / 2;
        int best = 0;
        for (char a : chars) {
            for (char b : chars) {
                if (a == b) continue;
                int diff = 0;
                int diffWithB = NEG_INF;
                for (char c : s) {
                    if (c == a) {
                        diff++;
                        if (diffWithB > NEG_INF) diffWithB++;
                    } else if (c == b) {
                        diffWithB = max(diffWithB, diff) - 1;
                        diff--;
                    } else continue;
                    if (diffWithB > NEG_INF) best = max(best, diffWithB);
                    if (diff < 0) diff = 0;
                }
            }
        }
        return best;
    }
};
