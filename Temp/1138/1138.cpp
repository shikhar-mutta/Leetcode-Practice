// Link: https://leetcode.com/problems/alphabet-board-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string alphabetBoardPath(string target) {
        int cr = 0, cc = 0;
        string res;
        for (char ch : target) {
            int idx = ch - 'a';
            int r = idx / 5, c = idx % 5;
            if (ch == 'z') {
                if (c < cc) res += string(cc - c, 'L');
                if (r > cr) res += string(r - cr, 'D');
            } else {
                if (r < cr) res += string(cr - r, 'U');
                if (r > cr) res += string(r - cr, 'D');
                if (c < cc) res += string(cc - c, 'L');
                if (c > cc) res += string(c - cc, 'R');
            }
            res += '!';
            cr = r; cc = c;
        }
        return res;
    }
};
