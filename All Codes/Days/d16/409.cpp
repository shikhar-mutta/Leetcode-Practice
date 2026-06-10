// Link: https://leetcode.com/problems/longest-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n). SC: O(1).
    int longestPalindrome(string s)
    {
        vector<int> freq(128, 0); // Assuming ASCII character set
        for (char c : s)
            freq[c]++;

        int length = 0;
        bool hasOdd = false;
        for (int f : freq)
        {
            length += f - (f % 2); // Add the largest even number less than or equal to f
            if (f % 2 != 0)        // if true then we can add one odd char to string
                hasOdd = true;
        }
        return hasOdd ? length + 1 : length;
    }
};
