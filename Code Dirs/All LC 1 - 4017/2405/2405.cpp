// Link: https://leetcode.com/problems/optimal-partition-of-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int parts = 1;
        int seen = 0;
        for (char c : s) {
            int bit = 1 << (c - 'a');
            if (seen & bit) {
                parts++;
                seen = 0;
            }
            seen |= bit;
        }
        return parts;
    }
};
