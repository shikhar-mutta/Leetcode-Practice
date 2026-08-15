// Link: https://leetcode.com/problems/can-convert-string-in-k-moves/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size() != t.size()) return false;
        vector<int> count(26, 0);
        for (int i = 0; i < (int)s.size(); i++) {
            int diff = ((t[i] - s[i]) % 26 + 26) % 26;
            if (diff == 0) continue;
            int needed = diff + 26 * count[diff];
            if (needed > k) return false;
            count[diff]++;
        }
        return true;
    }
};
