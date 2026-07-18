// Link: https://leetcode.com/problems/random-pick-with-blacklist/description/

#include <bits/stdc++.h>
using namespace std;

// Random Num Generator
class Solution
{
    vector<int> bl; // sorted blacklist
    int m;          // count of valid (whitelisted) numbers = n - blacklist.size()
    mt19937 rng;    // pseudo-random number generator
public:
    // TC: O(B log B). SC: O(B).
    Solution(int n, vector<int> &blacklist) : rng(random_device{}())
    {
        sort(blacklist.begin(), blacklist.end());
        bl = blacklist;
        m = n - (int)bl.size();
    }

    int pick()
    {
        // Pick the k-th (0-indexed) whitelisted number, k uniform in [0, m).
        int k = (int)(rng() % (unsigned)m);
        // Kth missing num
        int lo = 0, hi = (int)bl.size();
        while (lo < hi)
        {
            int mid = (lo + hi) / 2;
            if (bl[mid] - mid <= k)
                lo = mid + 1;
            else
                hi = mid;
        }
        return k + lo;
    }
};
