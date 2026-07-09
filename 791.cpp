// Link: https://leetcode.com/problems/custom-sort-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1).
    // Approach: Count the frequency of each character in s, then build the result string by appending characters in the order specified by order, followed by any remaining characters.
    string customSortString(string order, string s)
    {
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        string res;
        for (char c : order)
        {
            res.append(cnt[c - 'a'], c);
            cnt[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; i++)
            res.append(cnt[i], 'a' + i);
        return res;
    }
};
