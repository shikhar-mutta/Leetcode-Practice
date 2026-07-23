// Link: https://leetcode.com/problems/convert-to-base-2/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) SC: O(log n)
    // Approach: Greedy
    // 1. We can convert the number to base -2 by repeatedly dividing the number by -2 and keeping track of the remainders.
    // 2. If the remainder is negative, we need to adjust it by adding 2 and incrementing the quotient by 1.
    // 3. We continue this process until the number becomes 0, and we build the result string from the remainders.
    // 4. Finally, we return the result string.
    string baseNeg2(int n)
    {
        if (n == 0)
            return "0";
        string result;
        while (n != 0)
        {
            int r = n % -2;
            n /= -2;
            if (r < 0)
            {
                r += 2;
                n += 1;
            }
            result = char('0' + r) + result;
        }
        return result;
    }
};
