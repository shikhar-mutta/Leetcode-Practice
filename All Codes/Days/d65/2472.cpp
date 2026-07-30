// Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N^2), SC: O(1)
//  Approach: For each character, check for palindromes of odd and even lengths centered at that character. If a palindrome of length >= k is found, increment the count and skip to the end of that palindrome to avoid overlapping.
class Solution
{
public:
    int maxPalindromes(string s, int k)
    {
        if (k == 1)
            return s.size();
        int res = 0;
        int left = -1;

        for (int i = 0; i < s.size(); ++i)
        {
            bool skip = false;
            int l = i - 1;
            int r = i + 1;
            while (l > left && r < s.size())
            {
                if (s[l] != s[r])
                    break;
                if (r - l + 1 >= k)
                {
                    skip = true;
                    ++res;
                    left = r;
                    break;
                }
                --l;
                ++r;
            }
            if (skip)
                continue;
            l = i;
            r = i + 1;
            while (l > left && r < s.size())
            {
                if (s[l] != s[r])
                    break;
                if (r - l + 1 >= k)
                {
                    skip = true;
                    ++res;
                    left = r;
                    break;
                }
                --l;
                ++r;
            }
        }

        return res;
    }
};
