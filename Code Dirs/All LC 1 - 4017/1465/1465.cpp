// Link: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        long long maxH = max(horizontalCuts[0], h - horizontalCuts.back());
        for (int i = 1; i < (int)horizontalCuts.size(); i++)
            maxH = max(maxH, (long long)(horizontalCuts[i] - horizontalCuts[i-1]));

        long long maxW = max(verticalCuts[0], w - verticalCuts.back());
        for (int i = 1; i < (int)verticalCuts.size(); i++)
            maxW = max(maxW, (long long)(verticalCuts[i] - verticalCuts[i-1]));

        return (int)((maxH * maxW) % 1000000007);
    }
};
