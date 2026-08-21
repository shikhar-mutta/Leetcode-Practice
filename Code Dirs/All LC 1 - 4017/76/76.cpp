// Link: https://leetcode.com/problems/minimum-window-substring/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string minWindow(string s, string t)
    {
        if (s.size() < t.size() || t.empty())
            return "";

        int need[128] = {0};
        for (char c : t)
            need[(int)c]++;
        int missing = t.size(); // chars still to be matched in the window

        int bestLen = INT_MAX, bestStart = 0;
        int left = 0;
        for (int right = 0; right < (int)s.size(); right++)
        {
            // Extend window; if this char was needed, we covered one more.
            if (need[(int)s[right]]-- > 0)
                missing--;

            // Once all chars are covered, shrink from the left as far as possible.
            while (missing == 0)
            {
                if (right - left + 1 < bestLen)
                {
                    bestLen = right - left + 1;
                    bestStart = left;
                }
                if (++need[(int)s[left]] > 0)
                    missing++;
                left++;
            }
        }
        return bestLen == INT_MAX ? "" : s.substr(bestStart, bestLen);
    }
    // TC: O(n+m), SC: O(charset)
    // string minWindow(string s, string t)
    // {
    //     vector<int> freq(256, 0);

    //     for (auto ch : t)
    //         freq[ch]++;

    //     int l = 0;
    //     int r = 0;

    //     string res = "";
    //     int min_len = INT_MAX;

    //     int start = 0;
    //     int count = 0;

    //     for (auto ch : s)
    //     {
    //         if (freq[ch] > 0)
    //             count++;

    //         freq[ch]--;

    //         while (count == t.length())
    //         {
    //             int curr = r - l + 1;
    //             if (curr < min_len)
    //             {
    //                 min_len = curr;
    //                 start = l;
    //             }
    //             if (freq[s[l]] == 0)
    //                 count--;
    //             freq[s[l]]++;
    //             l++;
    //         }
    //         r++;
    //     }

    //     return min_len == INT_MAX ? "" : s.substr(start, min_len);
    // }
};
