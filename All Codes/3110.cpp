// Link: https://leetcode.com/problems/score-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int scoreOfString(string s)
    {
        // sum of |ASCII difference| between each pair of adjacent characters
        int score = 0;
        for (int i = 1; i < (int)s.size(); ++i)
            score += abs(s[i] - s[i - 1]);
        return score;
    }
};
