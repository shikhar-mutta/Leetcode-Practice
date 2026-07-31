// Link: https://leetcode.com/problems/last-substring-in-lexicographical-order/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
//  Approach: Two pointer approach. We maintain two pointers i and j, where i is the starting index of the current best substring and j is the starting index of the current candidate substring. We compare the characters at i+k and j+k, where k is the offset from the starting indices. If the characters are equal, we increment k to compare the next characters. If the character at i+k is less than the character at j+k, it means the substring starting at j is lexicographically larger, so we update i to be the maximum of i+k+1 and j, and move j to i+1. If the character at i+k is greater than the character at j+k, we simply move j to j+k+1. We continue this process until j+k reaches the end of the string. Finally, we return the substring starting at index i.
class Solution
{
public:
    string lastSubstring(string s)
    {
        int n = s.size();
        int i = 0, j = 1, k = 0;
        while (j + k < n)
        {
            if (s[i + k] == s[j + k])
                k++;
            else if (s[i + k] < s[j + k])
            {
                i = max(i + k + 1, j);
                j = i + 1;
                k = 0;
            }
            else
            {
                j = j + k + 1;
                k = 0;
            }
        }
        return s.substr(i);
    }
};