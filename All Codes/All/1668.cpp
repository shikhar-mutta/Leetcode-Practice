// Link: https://leetcode.com/problems/maximum-repeating-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m), SC: O(n)
    int maxRepeating(string sequence, string word)
    {
        int k = 0;
        string cur = word;
        // keep appending word while it's still a substring of sequence
        while (sequence.find(cur) != string::npos)
        {
            k++;
            cur += word;
        }
        return k;
    }
};
