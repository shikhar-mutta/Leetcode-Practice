// Link: https://leetcode.com/problems/find-if-digit-game-can-be-won/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    bool canAliceWin(vector<int> &nums)
    {
        int singleDigitSum = 0, DoubleDigitSum = 0;
        for (int num : nums)
        {
            if (num < 10)
                singleDigitSum += num;
            else
                DoubleDigitSum += num;
        }
        return singleDigitSum == DoubleDigitSum ? false : true;
    }
};
