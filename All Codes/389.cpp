// Link: https://leetcode.com/problems/find-the-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    char findTheDifference(string s, string t)
    {
        vector<int> count(26, 0);
        for (char c : t)
            count[c - 'a']++;
        for (char c : s)
            count[c - 'a']--;

        for (int i = 0; i < 26; i++)
            if (count[i] > 0)
                return 'a' + i;
        return ' ';
    }
};
