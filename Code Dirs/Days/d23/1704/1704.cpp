// Link: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool halvesAreAlike(string s)
    {
        string vowels = "aeiouAEIOU";
        int n = s.size(), cnt = 0;
        // +1 for a vowel in the first half, -1 in the second; alike iff net 0
        for (int i = 0; i < n; i++)
            if (vowels.find(s[i]) != string::npos)
                cnt += (i < n / 2) ? 1 : -1;
        return cnt == 0;
    }
};
