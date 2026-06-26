// Link: https://leetcode.com/problems/minimum-window-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string minWindow(string s, string t)
    {
        if (s.size() < t.size() || t.empty())
            return "";

        int need[128] = {0};
        for (char c : t)
            need[(int)c]++;
        int missing = t.size(); // chars still to be matched in the window

        int bestLen = INT_MAX, bestStart = 0;
        int left = 0;
        for (int right = 0; right < (int)s.size(); right++)
        {
            // Extend window; if this char was needed, we covered one more.
            if (need[(int)s[right]]-- > 0)
                missing--;

            // Once all chars are covered, shrink from the left as far as possible.
            while (missing == 0)
            {
                if (right - left + 1 < bestLen)
                {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                if (++need[(int)s[left]] > 0)
                    missing++;
                left++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
};
