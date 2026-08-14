// Link: https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;
        int low = 0, high = 0;
        for (int i = 0; i < n; i++) {
            if (locked[i] == '0') { low--; high++; }
            else if (s[i] == '(') { low++; high++; }
            else { low--; high--; }
            if (high < 0) return false;
            low = max(low, 0);
        }
        return low == 0;
    }
};
