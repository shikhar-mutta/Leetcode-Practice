// Link: https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //  1. We can use a vector of size 26 to keep track of the maximum length of valid substrings ending with each character.
    //  2. We iterate through the input string and for each character, we check if it is a continuation of the previous character in the wraparound string. If it is, we increment the current length of the valid substring. If not, we reset the current length to 1.
    //  3. We update the maximum length for the current character in the vector.
    //  4. Finally, we sum up the values in the vector to get the total number of unique substrings in the wraparound string.
    int findSubstringInWraproundString(string s)
    {
        vector<int> maxEnd(26, 0);
        int curLen = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (i > 0 && (s[i] - s[i - 1] == 1 || (s[i - 1] == 'z' && s[i] == 'a')))
                curLen++;
            else
                curLen = 1;
            maxEnd[s[i] - 'a'] = max(maxEnd[s[i] - 'a'], curLen);
        }
        int total = 0;
        for (int v : maxEnd)
            total += v;
        return total;
    }
};
