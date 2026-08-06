// Link: https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n)  SC: O(k)
// Approach: greedily scan rolls, maintaining a set of values seen in the
// current "round". Whenever the set covers all 1..k, a round completes
// (increment answer, reset set). The answer is (completed rounds + 1),
// since that many rounds are needed before a length-(rounds+1) sequence
// becomes impossible to form as a subsequence.
class Solution
{
public:
    int shortestSequence(vector<int> &rolls, int k)
    {
        vector<bool> seen(k + 1, false);
        int count = 0, rounds = 0;
        for (int r : rolls)
        {
            if (!seen[r])
            {
                seen[r] = true;
                count++;
            }
            if (count == k)
            {
                rounds++;
                count = 0;
                fill(seen.begin(), seen.end(), false);
            }
        }
        return rounds + 1;
    }
};
