// Link: https://leetcode.com/problems/max-difference-you-can-get-from-changing-an-integer/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxS = s;
        char target = 0;
        for (char c : s) if (c != '9') { target = c; break; }
        if (target != 0) for (char& c : maxS) if (c == target) c = '9';

        string minS = s;
        if (s[0] != '1') {
            for (char& c : minS) if (c == s[0]) c = '1';
        } else {
            char target2 = 0;
            for (int i = 1; i < (int)s.size(); i++) {
                if (s[i] != '0' && s[i] != s[0]) { target2 = s[i]; break; }
            }
            if (target2 != 0) for (int i = 1; i < (int)minS.size(); i++) if (minS[i] == target2) minS[i] = '0';
        }

        return stoi(maxS) - stoi(minS);
    }
};
