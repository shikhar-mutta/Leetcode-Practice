// Link: https://leetcode.com/problems/broken-calculator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int ops = 0;
        while (target > startValue) {
            if (target % 2 == 0) target /= 2;
            else target++;
            ops++;
        }
        return ops + (startValue - target);
    }
};
