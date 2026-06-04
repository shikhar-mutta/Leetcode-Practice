// Link: https://leetcode.com/problems/count-pairs-of-similar-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int similarPairs(vector<string> &words)
    {
        int cnt = 0;
        // Array of bitsets with 26 bits to represent each character A to Z
        bitset<26> bs[words.size()];

        // Create bitsets for each word to represent the unique characters
        for (int i = 0; i < words.size(); i++)
            for (char c : words[i])
                bs[i].set(c - 'a');

        // Compare the bitsets to count similar pairs
        for (int i = 0; i < words.size(); i++)
            for (int j = i + 1; j < words.size(); j++)
                if (bs[i] == bs[j])
                    cnt++;

        return cnt;
    }
};
