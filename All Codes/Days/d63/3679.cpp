// Link: https://leetcode.com/problems/minimum-discards-to-balance-inventory/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(max_value)
//  Approach: sliding window over the last w ORIGINAL positions (kept or
//  not). For each arrival, first evict kept items that fell out of the
//  window [i-w+1, i], then check the current count of this type within
//  the window: if still below m, keep it (add to window); otherwise
//  discard it.
class Solution
{
public:
    int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
    {
        int mx = *max_element(arrivals.begin(), arrivals.end());
        vector<int> mp(mx + 1, 0);
        int n = arrivals.size();
        int left = 0, right = 0;
        int ans = 0;
        while (right < n)
        {
            if (right - left + 1 > w)
            {
                mp[arrivals[left]]--;
                left++;
            }
            if (mp[arrivals[right]] < m)
                mp[arrivals[right]]++;
            else
            {
                ans++;
                arrivals[right] = 0;
            }
            right++;
        }
        return ans;
    }
};