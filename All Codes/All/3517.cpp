// Link: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N), SC: O(1)
    // Approach:
    //  1. Count the frequency of each character in the first half of the string.
    //  2. Reconstruct the first half of the string in lexicographical order based on the character counts.
    //  3. Mirror the first half to the second half to form the palindrome.
    // Note: The input string is guaranteed to be a palindrome, so we only need to consider the first half of the string for rearrangement.
    string smallestPalindrome(string s)
    {
        int n = s.size();
        int counts[26] = {0};

        // 1. O(N) 統計頻率
        for (int i = 0; i < n / 2; ++i)
        {
            counts[s[i] - 'a']++;
        }

        // 2. O(N) 原地重建前半段
        int idx = 0;
        for (int i = 0; i < 26; ++i)
        {
            while (counts[i]-- > 0)
            {
                s[idx++] = (char)(i + 'a');
            }
        }

        // 3. O(N) 鏡像複製到後半段
        for (int i = 0; i < n / 2; ++i)
        {
            s[n - 1 - i] = s[i];
        }

        return s;
    }
};
