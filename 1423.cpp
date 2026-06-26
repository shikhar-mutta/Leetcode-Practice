// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int w = n - k; // size of the contiguous block we leave behind
        if (w == 0)
            return total; // take every card

        // Minimize the sum of the kept window of size w; answer = total - that min.
        int windowSum = 0;
        for (int i = 0; i < w; i++)
            windowSum += cardPoints[i];
        int minWindow = windowSum;
        for (int i = w; i < n; i++)
        {
            windowSum += cardPoints[i] - cardPoints[i - w];
            minWindow = min(minWindow, windowSum);
        }
        return total - minWindow;
    }
};
