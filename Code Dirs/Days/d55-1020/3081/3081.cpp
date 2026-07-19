// Link: https://leetcode.com/problems/replace-question-marks-in-string-to-minimize-its-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string s.
    // SC: O(1) as we are using a fixed size array of 26
    //  26 for frequency counting and another fixed size array of 26 for the 'add'
    //  Approach:
    //   1. Count the frequency of each character in the string and the number of '?' characters.
    //   2. For each '?', find the character with the minimum frequency and replace it with that character. This ensures that we are always adding the least frequent character to the string, which minimizes the overall value of the string.
    //   3. Replace the '?' characters in the string with the characters we have chosen in step 2.
    //   4. Return the modified string.
    string minimizeStringValue(string s)
    {
        // Fast I/O to maximize competitive programming runtime efficiency
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int freq[26] = {0};
        int blanks = 0;

        // Step 1: Single pass to count existing frequencies and total '?'
        for (char c : s)
        {
            if (c != '?')
            {
                freq[c - 'a']++;
            }
            else
            {
                blanks++;
            }
        }

        // Step 2: Directly assign the best characters to an 'add' bucket array
        int add[26] = {0};
        while (blanks > 0)
        {
            int best_char = 0;
            // Find the character with the absolute minimum frequency right now
            for (int i = 1; i < 26; i++)
            {
                if (freq[i] < freq[best_char])
                {
                    best_char = i;
                }
            }
            // "Pick" this character
            add[best_char]++;
            freq[best_char]++;
            blanks--;
        }

        // Step 3: Replace '?' in-place using the available 'add' buckets sequentially
        int j = 0;
        for (char &c : s)
        {
            if (c == '?')
            {
                while (add[j] == 0)
                {
                    j++;
                }
                c = 'a' + j;
                add[j]--;
            }
        }

        return s;
    }
};