// Link: https://leetcode.com/problems/maximum-tastiness-of-candy-basket/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n + n log d), SC: O(1)
    int maximumTastiness(vector<int> &price, int k)
    {
        sort(price.begin(), price.end());
        int n = price.size();

        // Binary search the largest minimum-gap x that lets us pick k candies.
        int lo = 0, hi = price[n - 1] - price[0], ans = 0;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2; // candidate minimum gap
            if (canPick(price, k, mid))
            {
                ans = mid; // feasible → try for a larger gap
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1; // too large → shrink
            }
        }
        return ans;
    }

private:
    // Greedily check whether we can choose k candies each at least gap apart.
    bool canPick(vector<int> &price, int k, int gap)
    {
        int count = 1; // always take the first (cheapest)
        int last = price[0];
        for (int i = 1; i < (int)price.size(); i++)
        {
            if (price[i] - last >= gap)
            {
                count++;
                last = price[i];
                if (count == k)
                    return true;
            }
        }
        return count >= k;
    }
};
