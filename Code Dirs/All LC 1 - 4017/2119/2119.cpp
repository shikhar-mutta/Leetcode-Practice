// Link: https://leetcode.com/problems/a-number-after-a-double-reversal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        return num == 0 || num % 10 != 0;
    }
};
