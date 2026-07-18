// Link: https://leetcode.com/problems/first-unique-character-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) and SC: O(1)
    int firstUniqChar(string s)
    {
        int n = s.size(), index = n - 1;
        vector<int> freq(26, 0);
        for (auto &c : s)
            freq[c - 'a']++;
        for (int i = 0; i < n; i++)
            if (freq[s[i] - 'a'] == 1)
                return i;
        return index == n - 1 ? -1 : index;
    }
};
