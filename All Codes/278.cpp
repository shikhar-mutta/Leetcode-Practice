// Link: https://leetcode.com/problems/first-bad-version/description/

#include <bits/stdc++.h>
using namespace std;

// Forward declaration of the isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    // TC: O(log n), SC: O(1)
    // Binary search
    int firstBadVersion(int n)
    {
        int lo = 1, hi = n;
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid))
                hi = mid; // first bad is at mid or earlier
            else
                lo = mid + 1;
        }
        return lo;
    }
};
