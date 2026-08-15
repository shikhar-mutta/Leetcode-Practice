// Link: https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool queryString(string s, int n) {
        for (int i = 1; i <= n; i++) {
            string bin;
            int x = i;
            while (x) { bin += ('0' + (x & 1)); x >>= 1; }
            reverse(bin.begin(), bin.end());
            if (s.find(bin) == string::npos) return false;
        }
        return true;
    }
};
