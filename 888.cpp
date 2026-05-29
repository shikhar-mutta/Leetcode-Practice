// Link: https://leetcode.com/problems/fair-candy-swap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &aliceSizes, vector<int> &bobSizes)
    {
        int sumA = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumB = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int target = (sumA - sumB) / 2;
        unordered_set<int> setA(aliceSizes.begin(), aliceSizes.end());
        for (int y : bobSizes)
        {
            int x = y + target;
            if (setA.count(x))
                return {x, y};
        }
        return {};
    }
};
