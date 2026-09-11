// Link: https://leetcode.com/problems/most-common-word/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        // Count the frequency of each word in the paragraph
        unordered_map<string, int> wds;
        string st;
        int n = paragraph.size();
        // Convert the paragraph to lowercase and split it into words
        for (int i = 0; i < n; i++)
        {
            st = "";
            // Skip non-alphabetic characters and build the current word
            while (i < n && isalpha(paragraph[i]))
            { // Convert to lowercase and append to the current word
                st += tolower(paragraph[i]);
                i++;
            } // If we have a valid word, increment its frequency in the map
            if (st != "")
                wds[st]++;
        }
        // Create a set of banned words for O(1) lookups [IMP]
        unordered_set<string> bannedSet(banned.begin(), banned.end());

        string res = "";
        // Iterate through the word frequency map to find the most common non-banned word
        int maxFreq = 0;
        for (auto &it : wds)
        {
            if (bannedSet.find(it.first) == bannedSet.end() && it.second > maxFreq)
            {
                maxFreq = it.second;
                res = it.first;
            }
        }
        return res;
    }
};
