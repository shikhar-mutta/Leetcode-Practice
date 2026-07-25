// Link: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach:
//   1. We can keep track of the number of open brackets and the number of swaps needed to balance the string.
//   2. We can iterate through the string and for each character, we can check if it is an open bracket or a closed bracket.
//   3. If it is an open bracket, we can increment the number of open brackets. If it is a closed bracket, we can check if there are any open brackets. If there are, we can decrement the number of open brackets. If there are no open brackets, we can increment the number of swaps needed and increment the number of open brackets.
//   4. Finally, we can return the number of swaps needed to balance the string.
class Solution
{
public:
    int minSwaps(string s)
    {
        int open = 0, ans = 0;
        for (char ch : s)
        {
            if (ch == '[')
                open++;
            else
            {
                if (open != 0)
                    open--;
                else
                {
                    open++;
                    ans++;
                }
            }
        }
        return ans;
    }
};