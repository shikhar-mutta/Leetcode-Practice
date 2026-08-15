// Link: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string
    // SC: O(n) for the unordered_map used to count character frequencies
    //   Approach:
    //    1. Count the frequency of each character in the string using an unordered_map.
    //    2. Traverse the string to identify contiguous blocks of the same character and store their lengths in a vector of pairs (character, length).
    //    3. For each block, calculate the maximum length of a repeated character substring that can be formed by swapping one character from another block of the same character. This is done by taking the minimum of the block length + 1 (for the swap) and the total frequency of that character in the string.
    //    4. Additionally, check for cases where a single character block is surrounded by blocks of the same character, allowing for a swap that connects the two blocks. Update the maximum length accordingly.
    //    5. Return the maximum length found.
    int maxRepOpt1(string text)
    {
        int n = text.size();
        unordered_map<char, int> m;
        vector<pair<char, int>> vec;
        for (int i = 0; i < n; i++)
            m[text[i]]++;
        char ch = text[0];
        int freq = 1;
        for (int i = 1; i < n; i++)
        {
            if (ch == text[i])
                freq++;
            else
            {
                vec.push_back({ch, freq});
                ch = text[i];
                freq = 1;
            }
        }
        vec.push_back({ch, freq});
        int maxLen = INT_MIN;
        for (int i = 0; i < vec.size(); i++)
        {
            maxLen = max(maxLen, min(vec[i].second + 1, m[vec[i].first]));
        }
        for (int i = 1; i < vec.size() - 1; i++)
        {
            if (vec[i].second == 1 && (vec[i - 1].first == vec[i + 1].first))
            {
                int len = vec[i - 1].second + vec[i + 1].second;
                if (m[vec[i - 1].first] > len)
                    len++;
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};