// Link: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int diff = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            char expected = (i % 2 == 0) ? '0' : '1';
            if (s[i] != expected) diff++;
        }
        return min(diff, (int)s.size() - diff);
    }
};
