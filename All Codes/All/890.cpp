// Link: https://leetcode.com/problems/find-and-replace-pattern/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m), SC: O(m)
    //  Approach:
    //  1. Create two hash maps to store the mapping between characters in the word and the pattern.
    //  2. Iterate through each character in the word and pattern simultaneously.
    //  3. For each character, check if it has been seen before in the word and pattern.
    //  4. If it has been seen before, check if the mapping is consistent. If not, return false.
    //  5. If it has not been seen before, add the mapping to both hash maps.
    //  6. If all characters are consistent, return true.
    //  7. Iterate through the list of words and apply the matching function to each word. If it matches the pattern, add it to the result list.
    //  8. Return the result list containing all words that match the pattern.
    bool matches(const string &word, const string &pattern)
    {
        unordered_map<char, char> w2p, p2w;
        for (int i = 0; i < (int)word.size(); i++)
        {
            char w = word[i], p = pattern[i];
            if (w2p.count(w) && w2p[w] != p)
                return false;
            if (p2w.count(p) && p2w[p] != w)
                return false;
            w2p[w] = p;
            p2w[p] = w;
        }
        return true;
    }

    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> result;
        for (auto &word : words)
            if (matches(word, pattern))
                result.push_back(word);
        return result;
    }
};
