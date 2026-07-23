// Link: https://leetcode.com/problems/decoded-string-at-index/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) SC: O(1)
    // Approach:
    //  1. We first calculate the size of the decoded string by iterating through the input string and keeping track of the size of the decoded string.
    //  2. We then iterate through the input string in reverse order, keeping track of the current size of the decoded string and the current index k.
    //  3. If the current character is a digit, we divide the size by the digit and update k to be k % size.
    //  4. If the current character is a letter, we decrement the size and check if k is equal to 0. If it is, we return the current character as the result.
    //  5. We continue this process until we find the character at index k in the decoded string.
    string decodeAtIndex(string s, int k)
    {
        long long size = 0;
        int n = s.size();
        int i = 0;
        for (; i < n; i++)
        {
            char c = s[i];
            if (isdigit(c))
                size *= (c - '0');
            else
                size++;
            if (size >= k)
                break;
        }

        for (; i >= 0; i--)
        {
            char c = s[i];
            k %= size;
            if (k == 0 && isalpha(c))
                return string(1, c);
            if (isdigit(c))
                size /= (c - '0');
            else
                size--;
        }
        return "";
    }
};
