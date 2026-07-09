// Link: https://leetcode.com/problems/number-of-matching-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m * log k), SC: O(n + m), where n is the length of s, m is the number of words, and k is the average length of words.
    //  Approach: Preprocess the string s to store the indices of each character. For each word, use binary search to check if it is a subsequence of s by finding the next occurrence of each character in the word in the preprocessed indices.
    int numMatchingSubseq(const string &s, const vector<string> &words)
    {
        // Preprocess: store indices for each character
        vector<int> track[26];
        for (int i = 0; i < s.size(); ++i)
        {
            track[s[i] - 'a'].push_back(i);
        }

        int counter = 0;

        for (const auto &word : words)
        {
            int lastPos = -1;
            bool isSubseq = true;

            for (char c : word)
            {
                int idx = c - 'a';
                const auto &positions = track[idx];

                // Binary search for first position > lastPos
                auto it = upper_bound(positions.begin(), positions.end(), lastPos);
                if (it == positions.end())
                {
                    isSubseq = false;
                    break;
                }
                lastPos = *it;
            }

            if (isSubseq)
                counter++;
        }

        return counter;
    }
};
