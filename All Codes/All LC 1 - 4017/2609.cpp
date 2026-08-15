// Link: https://leetcode.com/problems/find-the-longest-balanced-substring-of-a-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int findTheLongestBalancedSubstring(string s)
    {
        // balanced = run of 0s then equal run of 1s. Track current zero/one counts.
        int zeros = 0, ones = 0, best = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                if (ones > 0)
                    zeros = ones = 0; // a new 0 after 1s starts a fresh block
                zeros++;
            }
            else
            {
                ones++;
                best = max(best, 2 * min(zeros, ones));
            }
        }
        return best;
    }
};
