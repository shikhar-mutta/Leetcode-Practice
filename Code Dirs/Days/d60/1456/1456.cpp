// Link: https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //  1. Use a sliding window approach to find the maximum number of vowels in any substring of length k in the given string s.
    //  2. Initialize a counter c to keep track of the number of vowels in the current window and a variable m to store the maximum number of vowels found so far.
    //  3. Define a lambda function v to check if a character is a vowel (a, e, i, o, u).
    //  4. Iterate through the string s, adding the value of v(s[i]) to c for each character in the string.
    //  5. If the current index i is greater than or equal to k, subtract the value of v(s[i - k]) from c to maintain the size of the sliding window.
    //  6. Update m with the maximum value between m and c after each iteration.
    //  7. After iterating through the string, return the value of m, which represents the maximum number of vowels found in any substring of length k.
    int maxVowels(string s, int k)
    {
        int c = 0, m = 0;
        auto v = [](char x)
        {
            return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
        };
        for (int i = 0; i < s.size(); i++)
        {
            c += v(s[i]);
            if (i >= k)
                c -= v(s[i - k]);
            m = max(m, c);
        }
        return m;
    }
};