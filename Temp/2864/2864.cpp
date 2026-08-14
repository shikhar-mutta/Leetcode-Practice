// Link: https://leetcode.com/problems/maximum-odd-binary-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        int n = s.size();
        string res(n, '0');
        for (int i = 0; i < ones - 1; i++) res[i] = '1';
        res[n - 1] = '1';
        return res;
    }
};
