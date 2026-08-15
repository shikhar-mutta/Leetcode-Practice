// Link: https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach:
//  1. We can iterate through the string and count the number of moves for Alice and Bob.
//  2. We can use a variable to keep track of the previous character and a counter to count the number of consecutive characters.
//  3. If the current character is the same as the previous character, we increment the counter. If the counter is greater than or equal to 3, we increment the corresponding player's move count.
//  4. If the current character is different from the previous character, we reset the counter to 1 and update the previous character.
//  5. After iterating through the string, we compare the move counts of Alice and Bob. If Alice's move count is greater than Bob's move count, we return true. Otherwise, we return false.
class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int n = colors.size();
        int prev = colors[0];
        int cnt = 1;
        int c1 = 0;
        int c2 = 0;
        for (int i = 1; i < n; i++)
        {
            if (colors[i] == prev)
            {
                cnt++;
            }
            else
            {
                if (colors[i - 1] == 'A')
                {
                    if (cnt >= 3)
                    {
                        c1 = c1 + cnt - 2;
                    }
                }
                else
                {
                    if (cnt >= 3)
                    {
                        c2 = c2 + cnt - 2;
                    }
                }
                cnt = 1;
                prev = colors[i];
            }
        }
        if (cnt >= 3)
        {
            if (colors[n - 1] == 'A')
            {
                c1 = c1 + cnt - 2;
            }
            else
            {
                c2 = c2 + cnt - 2;
            }
        }
        if (c1 <= c2)
            return false;
        return true;
    }
};