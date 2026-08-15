// Link: https://leetcode.com/problems/number-of-even-and-odd-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> ans(2, 0);
        int idx = 0;
        while (n > 0) {
            if (n & 1) ans[idx % 2]++;
            n >>= 1;
            idx++;
        }
        return ans;
    }
};
