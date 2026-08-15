// Link: https://leetcode.com/problems/construct-string-with-repeat-limit/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26] = {0};
        for (char c : s) cnt[c - 'a']++;
        string res;
        int i = 25;
        while (i >= 0) {
            if (cnt[i] == 0) { i--; continue; }
            int use = min(cnt[i], repeatLimit);
            res.append(use, (char)('a' + i));
            cnt[i] -= use;
            if (cnt[i] == 0) { i--; continue; }
            // need a separator from a smaller letter
            int j = i - 1;
            while (j >= 0 && cnt[j] == 0) j--;
            if (j < 0) break;
            res += (char)('a' + j);
            cnt[j]--;
        }
        return res;
    }
};
