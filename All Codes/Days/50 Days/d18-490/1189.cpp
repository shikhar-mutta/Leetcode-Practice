// Link: https://leetcode.com/problems/maximum-number-of-balloons/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) + O(1) ~ O(n). SC: O(1).
    int maxNumberOfBalloons(string text)
    {
        int ans = 0;
        string s = "balloon";
        int freq[26] = {0};
        for (auto ch : text)
            freq[ch - 'a']++;
        bool inVal = false;
        while (true)
        {
            for (auto ch : s)
            {
                freq[ch - 'a']--;
                if (freq[ch - 'a'] < 0)
                {
                    inVal = true;
                    break;
                }
            }
            if (inVal)
                break;
            ans++;
        }
        return ans;
    }
};
