// Link: https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//   Approach:
//     1. We can use a two-pointer approach to find the longest substring of all vowels in order.
//     2. We can iterate through the string and for each character, we can check if it is a vowel and if it is in the correct order.
//     3. If it is, we can increment the length of the current substring and the number of distinct vowels.
//     4. If it is not, we can reset the length and the number of distinct vowels
//     5. If the number of distinct vowels is 5 and the current character is 'u', we can update the result with the maximum length of the substring found so far.
class Solution
{
public:
    int longestBeautifulSubstring(string word)
    {
        string order = "aeiou";
        int res = 0, len = 1, distinct = 1;
        for (int i = 1; i < word.size(); ++i)
        {
            if (word[i] == word[i - 1])
            {
                ++len;
            }
            else if (order.find(word[i]) == order.find(word[i - 1]) + 1)
            {
                ++len;
                ++distinct;
            }
            else
            {
                len = 1;
                distinct = 1;
            }
            if (distinct == 5 && word[i] == 'u')
                res = max(res, len);
        }
        return res;
    }
};