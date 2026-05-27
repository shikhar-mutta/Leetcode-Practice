// Link: https://leetcode.com/problems/minimum-index-sum-of-two-lists/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;
        int cnt = 0, num = flowerbed.size();
        for (int i = 0; i < num; i++)
        {
            // i-1, i, and i+1 should all be 0 to plant a flower at index i
            if (flowerbed[i] || (i + 1 < num && flowerbed[i + 1]) || (i - 1 >= 0 && flowerbed[i - 1]))
                continue;

            flowerbed[i] = 1;
            // We have successfully planted a flower at index i, so we increment the count of planted flowers.
            if (++cnt == n)
                return true;
            i++; // i+1 is now adjacent to a flower, skip it
        }
        return false;
    }
};