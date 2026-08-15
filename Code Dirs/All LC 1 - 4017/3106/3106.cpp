// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        string res = s;
        for (int i = 0; i < (int)res.size(); i++) {
            int c = res[i] - 'a';
            int costToA = min(c, 26 - c);
            if (costToA <= k) {
                res[i] = 'a';
                k -= costToA;
            } else {
                int down = ((c - k) % 26 + 26) % 26;
                int up = (c + k) % 26;
                res[i] = 'a' + min(down, up);
                k = 0;
                break;
            }
        }
        return res;
    }
};
