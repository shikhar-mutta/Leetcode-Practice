// Link: https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach:
//  1. We can use a hash map to store the last index of each card.
//  2. We can iterate through the cards and for each card, we can check if it has been seen before.
//  3. If it has been seen before, we can calculate the distance between the current index and the last index of that card.
//  4. We can keep track of the minimum distance found so far.
//  5. Finally, we return the minimum distance found or -1 if no such pair exists.
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        const int n{static_cast<int>(cards.size())};
        static int vis[1000001]{};
        memset(vis, -1, sizeof(vis));
        int res{INT_MAX};
        for (int i{0}; i < n; ++i)
        {
            const int x{cards[i]};
            if (vis[x] != -1)
                res = min(res, i - vis[x] + 1);
            vis[x] = i;
        }
        return res == INT_MAX ? -1 : res;
    }
};
