// Link: https://leetcode.com/problems/maximum-product-of-word-lengths/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the number of words in the input vector.
    // SC: O(n) where n is the number of words in the input vector.
    // Approach:
    //   1. We can use a bitmask to represent the characters in each word. Each bit in the bitmask corresponds to a character in the alphabet, and is set to 1 if the character is present in the word, and 0 otherwise.
    //  2. We can then compare the bitmasks of each pair of words to check if they have any characters in common. If the bitwise AND of the two bitmasks is 0, then the two words have no characters in common.
    //  3. We can then calculate the product of the lengths of the two words and keep track of the maximum product found so far.
    //  4. Finally, we return the maximum product found.
    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        vector<int> mask(n, 0);
        for (int i = 0; i < n; i++)
            for (char c : words[i])
                mask[i] |= 1 << (c - 'a');

        int best = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((mask[i] & mask[j]) == 0)
                    best = max(best, (int)(words[i].size() * words[j].size()));
        return best;
    }
};
