// Link: https://leetcode.com/problems/increasing-decreasing-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) + O(26 * n) = O(n)
    string sortString(string s)
    {
        int freq[26] = {0};
        for (char c : s)
            freq[c - 'a']++;
        string ans;
        while (ans.size() < s.size())
        {
            for (int i = 0; i < 26; i++)
                if (freq[i] > 0)
                {
                    ans += (i + 'a');
                    freq[i]--;
                }
            for (int i = 25; i >= 0; i--)
                if (freq[i] > 0)
                {
                    ans += (i + 'a');
                    freq[i]--;
                }
        }
        return ans;
    }
};
