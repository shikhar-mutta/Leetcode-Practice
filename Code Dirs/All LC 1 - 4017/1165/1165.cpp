// Link: https://leetcode.com/problems/single-row-keyboard/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int pos[26];
        for (int i = 0; i < 26; i++) pos[keyboard[i]-'a'] = i;
        int total = 0, cur = 0;
        for (char c : word) {
            int p = pos[c-'a'];
            total += abs(p - cur);
            cur = p;
        }
        return total;
    }
};
