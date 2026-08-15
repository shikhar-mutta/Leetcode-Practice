// Link: https://leetcode.com/problems/minimum-number-of-frogs-croaking/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string.
    // SC: O(1) as we are using a constant amount of space for the
    // Approach:
    //   1. We will use five counters to keep track of the number of 'c', 'r', 'o', 'a', and 'k' characters we have seen so far.
    //   2. We will also keep track of the current number of frogs croaking and the maximum number of frogs croaking at any point in time.
    //   3. We will iterate through the input string and for each character, we will update the corresponding counter and the current number of frogs croaking.
    //   4. If at any point, the number of 'r' characters is greater than the number of 'c' characters, or the number of 'o' characters is greater than the number of 'r' characters, or the number of 'a' characters is greater than the number of 'o' characters, or the number of 'k' characters is greater than the number of 'a' characters, we will return -1 as it is not possible to have a valid croak sequence.
    //   5. Finally, we will check if the current number of frogs croaking is zero and all the counters are equal. If so, we will return the maximum number of frogs croaking at any point in time. Otherwise, we will return -1 as it is not possible to have a valid croak sequence.
    int minNumberOfFrogs(string croakOfFrogs)
    {
        int c = 0, r = 0, o = 0, a = 0, k = 0;
        int cur = 0, maxi = 0;

        for (char ch : croakOfFrogs)
        {
            if (ch == 'c')
            {
                c++;
                cur++;
            }
            else if (ch == 'r')
            {
                r++;
            }
            else if (ch == 'o')
            {
                o++;
            }
            else if (ch == 'a')
            {
                a++;
            }
            else if (ch == 'k')
            {
                k++;
                cur--;
            }
            else
            {
                return -1; // Invalid character
            }

            // Check validity after updating counts
            if (c < r || r < o || o < a || a < k)
                return -1;

            maxi = max(maxi, cur);
        }

        if (cur == 0 && c == r && r == o && o == a && a == k)
            return maxi;

        return -1;
    }
};