// Link: https://leetcode.com/problems/remove-letter-to-equalize-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool equalFrequency(string word)
    {
        int freq[26] = {0};
        for (char c : word)
            freq[c - 'a']++;
        // try removing one occurrence of each present letter
        for (int i = 0; i < 26; ++i)
        {
            if (!freq[i])
                continue;
            freq[i]--; // remove one
            int target = -1;
            bool ok = true;
            for (int j = 0; j < 26 && ok; ++j)
            {
                if (!freq[j])
                    continue; // ignore letters now absent
                if (target == -1)
                    target = freq[j];
                else if (freq[j] != target)
                    ok = false;
            }
            if (ok)
                return true;
            freq[i]++; // restore and try next
        }
        return false;
    }
};
