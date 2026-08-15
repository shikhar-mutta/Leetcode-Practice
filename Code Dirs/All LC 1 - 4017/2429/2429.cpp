// Link: https://leetcode.com/problems/minimize-xor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int k = __builtin_popcount(num2);
        int result = 0;
        for (int b = 31; b >= 0 && k > 0; b--) {
            if (num1 & (1 << b)) {
                result |= (1 << b);
                k--;
            }
        }
        for (int b = 0; b < 32 && k > 0; b++) {
            if (!(result & (1 << b))) {
                result |= (1 << b);
                k--;
            }
        }
        return result;
    }
};
