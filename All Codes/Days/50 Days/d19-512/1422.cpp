// Link: https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int maxScore(string s)
    {
        int rightOnes = count(s.begin(), s.end(), '1'), leftOnes = 0, maxScore = 0, n = s.size();

        if (s[0] == '0')
            ++leftOnes;
        else
            --rightOnes;

        maxScore = max(maxScore, leftOnes + rightOnes);
        for (int i = 1; i < n - 1; ++i)
        {
            if (s[i] == '0')
                ++leftOnes;
            else
                --rightOnes;

            maxScore = max(maxScore, leftOnes + rightOnes);
        }

        return maxScore;
    }
};
