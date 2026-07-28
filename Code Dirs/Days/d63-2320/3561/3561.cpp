// Link: https://leetcode.com/problems/resulting-string-after-adjacent-removals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: stack simulation. Two letters are removable if they're
// adjacent in the alphabet cyclically (difference of 1 or 25, covering
// the z-a wraparound). Push each char; if it's adjacent to the current
// stack top, pop instead of pushing.
class Solution
{
public:
    string resultingString(string s)
    {
        string sb;

        for (char ch : s)
        {
            if (!sb.empty())
            {
                char top = sb.back();
                int diff = abs(top - ch);

                if (diff == 1 || diff == 25)
                {
                    sb.pop_back();
                    continue;
                }
            }
            sb.push_back(ch);
        }

        return sb;
    }
};