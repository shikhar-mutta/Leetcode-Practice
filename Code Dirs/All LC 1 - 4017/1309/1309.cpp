// Link: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        int n = s.size();
        for (int i = 0; i < n; ) {
            if (i + 2 < n && s[i+2] == '#') {
                int num = (s[i] - '0') * 10 + (s[i+1] - '0');
                res += char('a' + num - 1);
                i += 3;
            } else {
                res += char('a' + (s[i] - '0') - 1);
                i++;
            }
        }
        return res;
    }
};
