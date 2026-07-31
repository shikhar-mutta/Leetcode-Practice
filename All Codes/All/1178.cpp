// Link: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(words + puzzles * 2^6)  SC: O(distinct word masks)
// Approach: encode each word as a 26-bit letter-presence mask, tally
// counts in a hashmap. For each puzzle, its first letter must be
// present, and the word must use only puzzle letters — enumerate every
// submask of the puzzle's remaining 25 bits, always including the first
// letter's bit, and sum the frequency of each submask that exists.
class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        unordered_map<int, int> wordMaskCount;
        for (auto &w : words)
        {
            int mask = 0;
            for (char c : w)
                mask |= (1 << (c - 'a'));
            wordMaskCount[mask]++;
        }

        vector<int> ans;
        for (auto &p : puzzles)
        {
            int full = 0;
            for (char c : p)
                full |= (1 << (c - 'a'));
            int firstBit = 1 << (p[0] - 'a');
            int rest = full ^ firstBit;

            long long count = 0;
            int sub = rest;
            while (true)
            {
                int mask = sub | firstBit;
                if (wordMaskCount.count(mask))
                    count += wordMaskCount[mask];
                if (sub == 0)
                    break;
                sub = (sub - 1) & rest;
            }
            ans.push_back((int)count);
        }
        return ans;
    }
};
