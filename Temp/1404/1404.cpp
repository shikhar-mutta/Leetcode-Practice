// Link: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int carry = 0, steps = 0;
        for (int i = (int)s.size() - 1; i > 0; i--) {
            int bit = (s[i] - '0') + carry;
            if (bit % 2 == 1) {
                steps += 2;
                carry = 1;
            } else {
                steps += 1;
            }
        }
        return steps + carry;
    }
};
