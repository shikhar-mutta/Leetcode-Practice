// Link: https://leetcode.com/problems/maximum-score-from-removing-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the input string.
// SC: O(n) for storing the intermediate string after removing the first substring.
// Approach:
//   1. We can remove the substring "ab" or "ba" from the string and gain points for each removal.
//   2. We can remove the substring with the higher score first to maximize the total score.
//   3. We can use a stack to keep track of the characters in the string and remove the substrings as we encounter them.
//   4. After removing the first substring, we can repeat the process for the remaining string to remove the second substring and gain points for each removal.
class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        char first = 'a', second = 'b';
        if (x < y)
        {
            swap(x, y);
            swap(first, second);
        }

        long long res = 0;
        string stk;
        for (char c : s)
        {
            if (c == second && !stk.empty() && stk.back() == first)
            {
                stk.pop_back();
                res += x;
            }
            else
                stk.push_back(c);
        }

        string stk2;
        for (char c : stk)
        {
            if (c == first && !stk2.empty() && stk2.back() == second)
            {
                stk2.pop_back();
                res += y;
            }
            else
                stk2.push_back(c);
        }
        return res;
    }
};