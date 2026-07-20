// Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m * k) where n is the length of the string s, m is the number of words, and k is the length of each word
    // SC: O(m * k) for the hash maps used to store the word counts
    //  Approach:
    //     1. Calculate the length of each word and the total length of all words
    //     2. Create a hash map to store the count of each word in the input list of words
    //     3. Iterate through the string s with different offsets (0 to wordLen - 1) to handle different starting positions
    //     4. For each offset, use a sliding window approach to check substrings of length equal to the total length of all words
    //     5. Maintain a hash map to count the words in the current window and compare it with the required word counts
    //     6. If the counts match, add the starting index of the window to the result list
    //     7. Return the result
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> res;
        int wordLen = words[0].size();
        int numWords = words.size();
        int n = s.size();
        int totalLen = wordLen * numWords;
        if (totalLen > n)
            return res;

        unordered_map<string, int> need;
        for (auto &w : words)
            need[w]++;

        for (int offset = 0; offset < wordLen; offset++)
        {
            unordered_map<string, int> window;
            int count = 0, left = offset;
            for (int right = offset; right + wordLen <= n; right += wordLen)
            {
                string w = s.substr(right, wordLen);
                if (need.count(w))
                {
                    window[w]++;
                    count++;
                    while (window[w] > need[w])
                    {
                        string wLeft = s.substr(left, wordLen);
                        window[wLeft]--;
                        count--;
                        left += wordLen;
                    }
                    if (count == numWords)
                    {
                        res.push_back(left);
                        string wLeft = s.substr(left, wordLen);
                        window[wLeft]--;
                        count--;
                        left += wordLen;
                    }
                }
                else
                {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
