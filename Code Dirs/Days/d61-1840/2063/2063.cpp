// Link: https://leetcode.com/problems/vowels-of-all-substrings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach:
//  1. We can iterate through the string and for each vowel, we can calculate the number of substrings that contain that vowel by multiplying the number of characters before it (i + 1) and the number of characters after it (n - i).
//  2. We can then add this value to the result and return the final result after iterating through the entire string.
class Solution
{
public:
    long long countVowels(string word)
    {
        long long n = word.size(), res = 0;
        string vowels = "aeiou";
        for (long long i = 0; i < n; ++i)
        {
            if (vowels.find(word[i]) != string::npos)
                res += (i + 1) * (n - i);
        }
        return res;
    }
};