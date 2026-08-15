// Link: https://leetcode.com/problems/find-xor-beauty-of-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int result = 0;
        for (int x : nums) result ^= x;
        return result;
    }
};
