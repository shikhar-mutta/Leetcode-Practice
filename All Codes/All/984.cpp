// Link: https://leetcode.com/problems/string-without-aaa-or-bbb/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(a + b) where a is the number of 'a's and b is the number of 'b's.
    // SC: O(a + b) where a is the number of 'a's and b is the number of 'b's.
    // Approach:
    //  1. We will keep adding 'a's and 'b's to the answer string until we have added all 'a's and 'b's.
    //  2. We will always try to add the character which has more count left.
    //  3. If both characters have the same count left, we will add one of them and then the other.
    //  4. We will keep track of how many characters we have added and make sure that we don't add more than 2 of the same character in a row.
    //  5. We will return the answer string after we have added all 'a's and 'b's.
    string strWithout3a3b(int a, int b)
    {
        string ans;
        while (a > 0 || b > 0)
        {
            if (a >= b)
            {
                int take = min(2, a);
                if (a == b)
                    take = 1;
                while (take--)
                {
                    ans += 'a';
                    a--;
                }
                if (b > 0)
                {
                    ans += 'b';
                    b--;
                }
            }
            else
            {
                int take = min(2, b);
                if (a == b)
                    take = 1;
                while (take--)
                {
                    ans += 'b';
                    b--;
                }
                if (a > 0)
                {
                    ans += 'a';
                    a--;
                }
            }
        }
        return ans;
    }
};