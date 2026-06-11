// Link: https://leetcode.com/problems/ransom-note/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> s;
        for (char c : magazine)
            s[c]++;
        for (char c : ransomNote)
        {
            if (s[c] == 0)
                return false;
            s[c]--;
        }
        return true;
    }
};
