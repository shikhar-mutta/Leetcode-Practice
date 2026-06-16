// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string getSmallestString(string s)
    {
        // One swap of adjacent same-parity digits. Swap at the earliest
        // position where it lowers a digit -> lexicographically smallest.
        for (int i = 0; i + 1 < (int)s.size(); i++)
        {
            if ((s[i] % 2) == (s[i + 1] % 2) && s[i] > s[i + 1])
            {
                swap(s[i], s[i + 1]);
                break;
            }
        }
        return s;
    }
};
