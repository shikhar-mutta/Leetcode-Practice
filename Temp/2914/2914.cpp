// Link: https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        for (int i = 0; i < (int)s.size(); i += 2)
            if (s[i] != s[i+1]) cnt++;
        return cnt;
    }
};
