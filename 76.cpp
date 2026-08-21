// Link: https://leetcode.com/problems/minimum-window-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> freq(256, 0);

        for (auto ch : t)
            freq[ch]++;

        int l = 0;
        int r = 0;

        string res = "";
        int min_len = INT_MAX;

        int start = 0;
        int count = 0;

        for (auto ch : s)
        {
            if (freq[ch] > 0)
                count++;

            freq[ch]--;

            while (count == t.length())
            {
                int curr = r - l + 1;
                if (curr < min_len)
                {
                    min_len = curr;
                    start = l;
                }
                if (freq[s[l]] == 0)
                    count--;
                freq[s[l]]++;
                l++;
            }
            r++;
        }

        return min_len == INT_MAX ? "" : s.substr(start, min_len);
    }
};
