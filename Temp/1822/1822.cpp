// Link: https://leetcode.com/problems/sign-of-the-product-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for (int x : nums) {
            if (x == 0) return 0;
            if (x < 0) sign = -sign;
        }
        return sign;
    }
};
