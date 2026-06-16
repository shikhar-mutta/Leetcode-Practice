// Link: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maxFreqSum(string s)
    {
        // count each letter, then take the highest vowel freq + highest consonant freq
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        for (char c : s)
            cnt[c - 'a']++;
        int maxV = 0, maxC = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
                maxV = max(maxV, cnt[i]);
            else
                maxC = max(maxC, cnt[i]);
        }
        return maxV + maxC;
    }
};
