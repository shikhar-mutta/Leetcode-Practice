// Link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        int best = -1;
        for (int i = 0; i < (int)s.size(); i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            else best = max(best, i - first[c] - 1);
        }
        return best;
    }
};
