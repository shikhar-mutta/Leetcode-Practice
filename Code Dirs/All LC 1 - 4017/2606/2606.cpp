// Link: https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> value(26);
        for (int i = 0; i < 26; i++) value[i] = i + 1;
        for (int i = 0; i < (int)chars.size(); i++) value[chars[i] - 'a'] = vals[i];

        int best = 0, cur = 0;
        for (char c : s) {
            cur += value[c - 'a'];
            cur = max(cur, 0);
            best = max(best, cur);
        }
        return best;
    }
};
