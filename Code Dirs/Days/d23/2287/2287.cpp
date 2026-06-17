// Link: https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m), SC: O(1)
    int rearrangeCharacters(string s, string target)
    {
        int cntS[26] = {0}, cntT[26] = {0};
        for (char c : s)
            cntS[c - 'a']++;
        for (char c : target)
            cntT[c - 'a']++;

        // copies limited by the scarcest required letter: min(have / need)
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++)
            if (cntT[i])
                ans = min(ans, cntS[i] / cntT[i]);
        return ans;
    }
};
