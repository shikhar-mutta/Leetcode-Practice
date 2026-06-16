// Link: https://leetcode.com/problems/majority-frequency-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string majorityFrequencyGroup(string s)
    {
        unordered_map<char, int> cnt;
        for (char c : s) // count frequency of each character
            cnt[c]++;
        unordered_map<int, string> groups;
        for (auto &[ch, f] : cnt) // group characters by frequency
            groups[f] += ch;

        int bestFreq = 0;
        size_t bestSize = 0;
        for (auto &[f, chars] : groups)
            if (chars.size() > bestSize || (chars.size() == bestSize && f > bestFreq))
            {
                bestSize = chars.size();
                bestFreq = f;
            }
        string res = groups[bestFreq];
        sort(res.begin(), res.end()); // deterministic order
        return res;
    }
};
