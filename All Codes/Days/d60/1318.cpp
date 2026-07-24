// Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(max(a,b,c))) SC: O(1)
    //  Approach:
    //  1. We can use a bit manipulation approach to solve this problem. We can start from the least significant bit of a, b and c and check if the bits are equal or not. If they are not equal, we can increment the answer by 1. We can then right shift a, b and c by 1 and repeat the process until all the bits are processed.
    // 2. We can use a while loop to iterate through the bits of a, b and c until all the bits are processed. We can use the bitwise AND operator to get the least significant bit of a, b and c and check if they are equal or not. If they are not equal, we can increment the answer by 1. We can then right shift a, b and c by 1 and repeat the process until all the bits are processed.
    // 3. Finally, we can return the answer as the result.
    int minFlips(int a, int b, int c)
    {

        int ans = 0;

        while (a || b || c)
        {

            int abit = a & 1;
            int bbit = b & 1;
            int cbit = c & 1;

            if (cbit == 1)
            {
                if (abit == 0 && bbit == 0)
                    ans++;
            }
            else
            {
                if (abit == 1)
                    ans++;

                if (bbit == 1)
                    ans++;
            }

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return ans;
    }
};