// Link: https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the size of the input array. SC: O(1)
    bool hasTrailingZeros(vector<int> &nums)
    {
        int cnt = 2;
        for (int num : nums)
        {
            if (num % 2 == 0)
            {
                cnt--;
                if (cnt == 0) // Early Stopping
                    return true;
            }
        }
        return false;
    }
};
