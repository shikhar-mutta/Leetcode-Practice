// Link: https://leetcode.com/problems/word-subsets/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m), where n is the number of words in words1 and m is the average length of the words in words1 and words2.
    // SC: O(1), since we are using a fixed size array of 26 to store the character counts.
    // Approach:
    //  1. We first create an array maxCount of size 26 to store the maximum count of each character in words2.
    //  2. We then iterate through each word in words2 and update the maxCount array with the maximum count of each character.
    //  3. Next, we iterate through each word in words1 and check if it is a universal word by comparing its character counts with the maxCount array.
    //  4. If a word in words1 has character counts greater than or equal to the maxCount array for all characters, we add it to the result vector.
    //  5. Finally, we return the result vector containing all the universal words from words1.
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        int maxCount[26] = {0};
        for (auto &w : words2)
        {
            int count[26] = {0};
            for (char c : w)
                count[c - 'a']++;
            for (int i = 0; i < 26; i++)
                maxCount[i] = max(maxCount[i], count[i]);
        }

        vector<string> result;
        for (auto &w : words1)
        {
            int count[26] = {0};
            for (char c : w)
                count[c - 'a']++;
            bool ok = true;
            for (int i = 0; i < 26; i++)
            {
                if (count[i] < maxCount[i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                result.push_back(w);
        }
        return result;
    }
};
