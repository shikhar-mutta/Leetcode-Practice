// Link: https://leetcode.com/problems/push-dominoes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";
        int n = s.size();
        string res = s;
        int prev = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '.') continue;
            if (s[prev] == s[i]) {
                for (int j = prev + 1; j < i; j++) res[j] = s[i];
            } else if (s[prev] == 'R' && s[i] == 'L') {
                int lo = prev + 1, hi = i - 1;
                while (lo < hi) { res[lo++] = 'R'; res[hi--] = 'L'; }
            }
            prev = i;
        }
        return res.substr(1, dominoes.size());
    }
};
