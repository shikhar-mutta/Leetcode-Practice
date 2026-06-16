// Link: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maximumLengthSubstring(string s)
    {
        // sliding window: shrink from left whenever a char's count exceeds 2
        int cnt[26] = {0}, left = 0, best = 0;
        for (int right = 0; right < (int)s.size(); ++right)
        {
            cnt[s[right] - 'a']++;
            while (cnt[s[right] - 'a'] > 2) // too many of this char -> drop from left
                cnt[s[left++] - 'a']--;
            best = max(best, right - left + 1);
        }
        return best;
    }
};
