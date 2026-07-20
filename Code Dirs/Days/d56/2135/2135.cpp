// Link: https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(N * M) where N is the number of words in targetWords and M is the average length of the words in targetWords.
    // SC: O(N) where N is the number of words in startWords.
    // Approach:
    //   1. We will use a bitmask to represent each word in startWords and store them in a set.
    //   2. For each word in targetWords, we will create a bitmask and check if we can remove one letter from it to match any of the bitmasks in startWords.
    //   3. If we can find a match, we will increment the count and break out of the loop for that word.
    //   4. Finally, we will return the count of words in targetWords that can be formed by adding one letter to a word in startWords.
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_set<int> startMasks;
        for (auto &w : startWords)
        {
            int mask = 0;
            for (char c : w)
                mask |= (1 << (c - 'a'));
            startMasks.insert(mask);
        }

        int count = 0;
        for (auto &w : targetWords)
        {
            int mask = 0;
            for (char c : w)
                mask |= (1 << (c - 'a'));
            for (char c : w)
            {
                int candidate = mask & ~(1 << (c - 'a'));
                if (startMasks.count(candidate))
                {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};
