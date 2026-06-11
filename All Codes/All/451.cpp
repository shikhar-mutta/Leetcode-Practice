// Link: https://leetcode.com/problems/sort-characters-by-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), SC: O(n)
    string frequencySort(string s)
    {
        vector<int> freq(256, 0);
        for (char c : s)
            freq[c]++;

        vector<pair<int, char>> charFreq;

        for (int i = 0; i < 256; i++)
            if (freq[i] > 0)
                charFreq.push_back({freq[i], (char)i});

        sort(charFreq.begin(), charFreq.end(), [](const pair<int, char> &a, const pair<int, char> &b)
             { if (a.first == b.first)
                   return a.second < b.second; // Sort by character if frequencies are equal
               return a.first > b.first; }); // Sort by frequency

        string result;
        result.reserve(s.size());
        for (const auto &p : charFreq)
            result += string(p.first, p.second);
        return result;
    }
};
