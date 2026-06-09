// Link: https://leetcode.com/problems/valid-anagram/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool isAnagram(string s, string t)
    {
        vector<int> count(26, 0);
        for (char &c : s)
            count[c - 'a']++;
        for (char &c : t)
            count[c - 'a']--;
        for (int &c : count)
            if (c != 0)
                return false;
        return true;
    }
};
