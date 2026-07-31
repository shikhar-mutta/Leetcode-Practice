// Link: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n + m)  SC: O(1)
// Approach: AND and XOR both distribute: XOR of all (a&b) equals
// (XOR of all a) & (XOR of all b), by bitwise linearity.
class Solution
{
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2)
    {
        int x1 = 0, x2 = 0;
        for (int x : arr1)
            x1 ^= x;
        for (int x : arr2)
            x2 ^= x;
        return x1 & x2;
    }
};
