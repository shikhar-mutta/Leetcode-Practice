// Link: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach:
    //   1. We can iterate through the string and for each character, we can find the first and last occurrence of that character. If the first occurrence is less than the last occurrence, we can create a set of characters between the first and last occurrence and add the size of that set to the result. Finally, we can return the result.
    int countPalindromicSubsequence(string s)
    {
        int res = 0;
        for (char c = 'a'; c <= 'z'; ++c)
        {
            int first = s.find(c), last = s.rfind(c);
            if (first == string::npos || first >= last)
                continue;
            unordered_set<char> mid(s.begin() + first + 1, s.begin() + last);
            res += mid.size();
        }
        return res;
    }
};
