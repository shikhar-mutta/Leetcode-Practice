// Link: https://leetcode.com/problems/number-of-even-and-odd-bits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n). SC: O(1).
    vector<int> evenOddBit(int n)
    {
        int even = 0, odd = 0;
        bool isEven = true;
        while (n > 0)
        {
            if ((n & 1) == 1)
            {
                if (isEven)
                    even++;
                else
                    odd++;
            }
            isEven = !isEven;
            n >>= 1;
        }
        return {even, odd};
    }
};
