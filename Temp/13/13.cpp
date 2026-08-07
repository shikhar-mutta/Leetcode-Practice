// Link: https://leetcode.com/problems/roman-to-integer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: sum symbol values left to right; subtract twice when a smaller value precedes a larger one (subtractive form)
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> val = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int total = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int cur = val[s[i]];
            if (i + 1 < (int)s.size() && cur < val[s[i+1]]) total -= cur;
            else total += cur;
        }
        return total;
    }
};
