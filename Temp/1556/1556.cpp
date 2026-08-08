// Link: https://leetcode.com/problems/thousand-separator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string thousandSeparator(int n) {
        string s = to_string(n);
        string res;
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            res += s[i];
            count++;
            if (count % 3 == 0 && i != 0) res += '.';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
