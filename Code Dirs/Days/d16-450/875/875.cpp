// Link: https://leetcode.com/problems/koko-eating-bananas/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log m). SC: O(1)
    int minEatingSpeed(vector<int> &piles, int h)
    {
        auto calculateTotalHours = [&](vector<int> &piles, int speed, int h)
        {
            int totalH = 0;
            for (int bananas : piles)
            {
                totalH += ceil((double)bananas / speed);
                if (totalH > h)
                    return false; // Early exit if total hours exceed h
            }
            return totalH <= h;
        };
        int maxPile = *max_element(piles.begin(), piles.end());
        // BS on k, the eating speed
        int low = 1, high = maxPile;
        int ans = maxPile, mid;
        bool isPossible;
        // Binary search on answer space
        while (low <= high)
        {
            mid = (low + high) / 2;
            isPossible = calculateTotalHours(piles, mid, h);

            // If possible, try smaller speed
            if (isPossible)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};