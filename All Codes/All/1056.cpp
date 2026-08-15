// Link: https://leetcode.com/problems/confusing-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<int,int> rotate = {{0,0},{1,1},{6,9},{8,8},{9,6}};
        string s = to_string(n);
        string rotated;
        for (int i = s.size() - 1; i >= 0; i--) {
            int d = s[i] - '0';
            if (!rotate.count(d)) return false;
            rotated += ('0' + rotate[d]);
        }
        return rotated != s;
    }
};
