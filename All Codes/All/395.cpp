// Link: https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), SC: O(n)
    //  Approach:
    //  1. If the length of the string is less than k, return 0
    //  2. Count the frequency of each character in the string.
    //  3. Iterate through the string and check if the frequency of the character is less than k. If it is, split the string into two substrings and recursively call the function on both substrings. Return the maximum of the two results.
    //  4. If all characters have a frequency greater than or equal to k, return the length of the string.
    int longestSubstring(string s, int k)
    {
        if ((int)s.size() < k)
            return 0;

        int cnt[26] = {0};
        for (char c : s)
            cnt[c - 'a']++;

        for (int i = 0; i < (int)s.size(); i++)
        {
            if (cnt[s[i] - 'a'] < k)
            {
                int j = i;
                while (j < (int)s.size() && cnt[s[j] - 'a'] < k)
                    j++;
                int left = longestSubstring(s.substr(0, i), k);
                int right = longestSubstring(s.substr(j), k);
                return max(left, right);
            }
        }
        return s.size();
    }
};
