// Link: https://leetcode.com/problems/lexicographically-smallest-beautiful-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k), SC: O(1)
//  Approach: We can start from the end of the string and try to increase the character at that position. If we can increase it, we fill the rest of the string with the smallest valid characters. If we cannot increase the character at that position, we move to the previous position and try again. We repeat this process until we find a valid string or we reach the beginning of the string.
class Solution
{
public:
    string smallestBeautifulString(string s, int k)
    {
        int n = s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            // Try increasing s[i]
            for (char ch = s[i] + 1; ch < 'a' + k; ch++)
            {
                // Check if placing ch at i is valid
                if ((i > 0 && s[i - 1] == ch) || (i > 1 && s[i - 2] == ch))
                    continue;
                s[i] = ch;
                // Fill the remaining positions with the smallest valid letters
                bool ok = true;
                for (int j = i + 1; j < n; j++)
                {
                    bool found = false;
                    for (char c = 'a'; c < 'a' + k; c++)
                    {
                        if ((j > 0 && s[j - 1] == c) ||
                            (j > 1 && s[j - 2] == c))
                            continue;
                        s[j] = c;
                        found = true;
                        break;
                    }
                    if (!found)
                    {
                        ok = false;
                        break;
                    }
                }
                if (ok)
                    return s;
            }
        }
        return "";
    }
};
