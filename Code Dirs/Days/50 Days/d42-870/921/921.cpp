// Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n). SC: O(1).
// Approach: We can use a counter to keep track of the number of unmatched '(' and the number of ')' needed so far. We iterate through the string and for each character, if it is '(', we increment the counter. If it is ')', we check if there is an unmatched '('. If there is, we decrement the counter. If there isn't, we increment the number of ')' needed. At the end, we return the sum of the number of unmatched '(' and the number of ')' needed.
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int open = 0, adds = 0; // open = unmatched '(', adds = ')' needed so far
        for (char c : s)
        {
            if (c == '(')
                open++;
            else if (open > 0)
                open--;
            else
                adds++;
        }
        return adds + open;
    }
};
