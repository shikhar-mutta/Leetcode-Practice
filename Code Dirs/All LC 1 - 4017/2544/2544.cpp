// Link: https://leetcode.com/problems/alternating-digit-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int sum = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            int d = s[i] - '0';
            sum += (i % 2 == 0) ? d : -d;
        }
        return sum;
    }
};
