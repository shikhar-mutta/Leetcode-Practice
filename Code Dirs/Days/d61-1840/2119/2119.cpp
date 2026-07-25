// Link: https://leetcode.com/problems/a-number-after-a-double-reversal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1)
// SC: O(1)
// Approach:
//  1. If the number is 0, then it will remain 0 after double reversal.
//  2. If the number ends with a 0, then after the first reversal, the number will have leading zeros which will be removed in the second reversal, resulting in a different number.
//  3. If the number does not end with a 0, then it will remain the same after double reversal.
class Solution
{
public:
    bool isSameAfterReversals(int num) { return num == 0 || num % 10 != 0; }
};
