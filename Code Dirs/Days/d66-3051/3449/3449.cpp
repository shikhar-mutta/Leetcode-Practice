// Link: https://leetcode.com/problems/maximize-the-minimum-game-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(maxVal))  SC: O(1)
//  Approach: reducing a single value x to 0 via repeated floor-sqrt-style operations takes O(log(x)) time. We can use binary search to find the maximum possible minimum score. For each candidate minimum score t, we can check if it is possible to achieve that score by iterating through the points and calculating how many moves are needed to reduce each point to at least t. If the total number of moves exceeds M, then it is not possible to achieve that score.
using ll = long long;
bool possible(ll t, const vector<int> &pts, int M)
{
    ll mv = 0, ext = 0, bon = 0;
    for (int p : pts)
    {
        ll req = (t + p - 1LL) / p;
        if (ext >= req)
        {
            ext = 0;
            bon++;
        }
        else
        {
            ll d = req - ext;
            mv += 2 * d - 1 + bon;
            ext = d - 1;
            bon = 0;
        }
        if (mv > M)
            return false;
    }
    return true;
}

class Solution
{
public:
    long long maxScore(vector<int> &pts, int M)
    {
        if (M < pts.size())
            return 0;
        ll lo = 1, hi = 1e18, ans = 0;
        while (lo <= hi)
        {
            ll mid = lo + (hi - lo) / 2;
            if (possible(mid, pts, M))
            {
                ans = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        return ans;
    }
};
