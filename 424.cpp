// Link: https://leetcode.com/problems/longest-repeating-character-replacement/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int count[26] = {0};
        int left = 0, maxCount = 0, best = 0;
        for (int right = 0; right < (int)s.size(); right++)
        {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);
            while (right - left + 1 - maxCount > k)
            {
                count[s[left] - 'A']--;
                left++;
            }
            best = max(best, right - left + 1);
        }
        return best;
    }
};
