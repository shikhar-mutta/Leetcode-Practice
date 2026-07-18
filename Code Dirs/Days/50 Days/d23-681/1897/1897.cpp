// Link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) and SC: O(1)
    bool makeEqual(vector<string> &words)
    {
        int freq[26] = {0};
        for (auto &w : words)
            for (char c : w)
                freq[c - 'a']++;

        int n = words.size();
        // each letter must split evenly across all words
        for (int f : freq)
            if (f % n)
                return false;
        return true;
    }
};
