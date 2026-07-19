// Link: https://leetcode.com/problems/maximize-score-of-numbers-in-ranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of st.
    // SC: O(1) where n is the number of st.
    // Approach:
    //  1. Sort the st in ascending order.
    //  2. Use binary search to find the maximum possible score.
    //  3. For each mid value, check if it is possible to achieve that score by iterating through the st and checking if the current score can be achieved by adding k to the previous score.
    //  4. If it is possible, then update the answer and search for a higher score. Otherwise, search for a lower score.
    //  5. Return the maximum possible score.
    bool possible(vector<int> &st, int d, int k)
    {
        long long curr = st[0] - k;
        for (auto x : st)
        {
            if (curr + k <= 1LL * x + d)
            {
                curr = max(curr + k, 1LL * x);
            }
            else
                return false;
        }
        return true;
    }
    int maxPossibleScore(vector<int> &st, int d)
    {
        sort(st.begin(), st.end());
        int l = 0;
        int r = st.back() + d;
        int ans = 0;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (possible(st, d, mid))
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};