// Link: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    //  Approach:
    //   1. Count the frequency of each character in the string.
    //   2. For each character, calculate the cost of making it the base frequency
    //      a. If the frequency of a character is less than the base frequency, we need to delete all occurrences of that character.
    //      b. If the frequency of a character is greater than the base frequency + k, we need to delete the excess occurrences of that character.
    //   3. Keep track of the minimum cost across all characters and return it.
    //   4. The base frequency is the frequency of the character we are currently considering as the base.
    //   5. The cost is the total number of deletions needed to make the string k-special with respect to the base frequency.
    int minimumDeletions(string word, int k)
    {
        int freq[26] = {};
        for (char c : word)
            freq[c - 'a']++;
        int ans = INT_MAX;
        for (int b = 0; b < 26; b++)
        {
            if (freq[b] == 0)
                continue;
            int base = freq[b];
            int cost = 0;
            for (int c = 0; c < 26; c++)
            {
                if (freq[c] == 0)
                    continue;
                if (freq[c] < base)
                    cost += freq[c];
                else if (freq[c] > base + k)
                    cost += freq[c] - (base + k);
            }
            ans = min(ans, cost);
        }
        return ans;
    }
};
