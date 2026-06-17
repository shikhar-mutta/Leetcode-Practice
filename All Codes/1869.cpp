// Link: https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    bool checkZeroOnes(string s)
    {
        int best[2] = {0, 0}, cur = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            cur = (i && s[i] == s[i - 1]) ? cur + 1 : 1;   // current run length
            best[s[i] - '0'] = max(best[s[i] - '0'], cur); // track longest per digit
        }
        return best[1] > best[0]; // longest 1-run beats longest 0-run
    }
};
