// Link: https://leetcode.com/problems/simplified-fractions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        for (int num = 1; num <= n; num++) {
            for (int denom = num + 1; denom <= n; denom++) {
                if (__gcd(num, denom) == 1) {
                    res.push_back(to_string(num) + "/" + to_string(denom));
                }
            }
        }
        return res;
    }
};
