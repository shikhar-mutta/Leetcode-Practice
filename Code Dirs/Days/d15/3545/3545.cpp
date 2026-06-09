// Link: https://leetcode.com/problems/minimum-deletions-for-at-most-k-distinct-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) SC: O(1)
    int minDeletion(string s, int k)
    {
        vector<int> freq(26, 0);
        int cnt = 0;
        for (char c : s)
        {
            if (freq[c - 'a'] == 0)
                cnt++;
            freq[c - 'a']++;
        }
        if (cnt <= k)
            return 0;
        sort(freq.rbegin(), freq.rend());
        int ans = 0;
        for (int i = k; i < 26; i++)
        {
            ans += freq[i];
        }
        return ans;
    }
};
