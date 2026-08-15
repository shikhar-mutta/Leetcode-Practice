// Link: https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int maxOnes = 0, maxZeros = 0, cur = 1;
        for (int i = 1; i <= (int)s.size(); i++) {
            if (i < (int)s.size() && s[i] == s[i-1]) {
                cur++;
            } else {
                if (s[i-1] == '1') maxOnes = max(maxOnes, cur);
                else maxZeros = max(maxZeros, cur);
                cur = 1;
            }
        }
        return maxOnes > maxZeros;
    }
};
