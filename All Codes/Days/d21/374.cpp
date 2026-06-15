// Link: https://leetcode.com/problems/guess-number-higher-or-lower/description/

#include <bits/stdc++.h>
using namespace std;

// Forward declaration of guess API.
// returns -1 if num > pick, 1 if num < pick, 0 if num == pick.
int guess(int num);

class Solution
{
public:
    // TC: O(log n), SC: O(1)
    // Binary search
    int guessNumber(int n)
    {
        int lo = 1, hi = n;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int g = guess(mid);
            if (g == 0)
                return mid;
            if (g < 0)
                hi = mid - 1; // mid is too high
            else
                lo = mid + 1; // mid is too low
        }
        return -1;
    }
};
