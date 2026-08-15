// Link: https://leetcode.com/problems/single-number-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: XOR all numbers to get a^b (the two singles), isolate any set bit to split nums into two
// groups by that bit, XOR each group separately to recover a and b
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (int x : nums) xorAll ^= x;
        int diffBit = xorAll & (-xorAll);
        int a = 0, b = 0;
        for (int x : nums) {
            if (x & diffBit) a ^= x;
            else b ^= x;
        }
        return {a, b};
    }
};
