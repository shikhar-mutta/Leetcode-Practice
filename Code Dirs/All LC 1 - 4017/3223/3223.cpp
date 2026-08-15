// Link: https://leetcode.com/problems/minimum-length-of-string-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            res += (freq[i] % 2 == 1) ? 1 : 2;
        }
        return res;
    }
};
