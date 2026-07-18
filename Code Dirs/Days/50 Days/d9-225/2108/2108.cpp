// Link: https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach 1: Two Pointers TC: O(n * m) , SC: O(1) —
    // preferred: early exit on mismatch, no extra allocation
    string firstPalindrome(vector<string> &words)
    {
        for (const string &word : words)
        {
            bool isPalindrome = true;
            int left = 0, right = (int)word.size() - 1;
            while (left < right)
            {
                if (word[left] != word[right])
                {
                    isPalindrome = false;
                    break;
                }
                left++;
                right--;
            }
            if (isPalindrome)
            {
                return word;
            }
        }
        return "";
    }
    // // Approach 2: Using reverse iterators TC: O(n * m) , SC: O(m)
    // string firstPalindrome(vector<string> &words)
    // {
    //     for (const string &word : words)
    //     {
    //         string rev(word.rbegin(), word.rend());
    //         if (word == rev)
    //             return word;
    //     }
    //     return "";
    // }
};
