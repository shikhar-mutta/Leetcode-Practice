// Link: https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evens = 0;
        for (int x : nums) if (x % 2 == 0) evens++;
        return evens >= 2;
    }
};
