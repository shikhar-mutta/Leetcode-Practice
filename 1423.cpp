// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int curS = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0); // curS = actual running window sum, kept separate from the best-seen answer
        int maxS = curS;
        for (int i = 0; i < k; i++)
        {
            // was: fed maxS (the running MAX, not the running SUM) back in as the base for the
            // next swap, so once maxS got inflated by an earlier step every later swap used a
            // wrong baseline sum instead of the actual sum after the true swap sequence
            curS = curS - cardPoints[k - 1 - i] + cardPoints[n - 1 - i];
            maxS = max(maxS, curS);
        }
        return maxS;
    }
};
