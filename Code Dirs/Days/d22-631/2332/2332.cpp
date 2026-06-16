// Link: https://leetcode.com/problems/the-latest-time-to-catch-a-bus/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + mlogm). SC: O(1)
    int latestTimeCatchTheBus(vector<int> &b, vector<int> &p, int cap)
    {
        int n = b.size();
        sort(b.begin(), b.end());
        sort(p.begin(), p.end());
        int j = 0; // for each passenger
        int c = 0;
        for (int i = 0; i < b.size(); i++) // for each bus
        {
            c = 0;
            while (c < cap && j < p.size() && p[j] <= b[i])
                c++, j++;
        }

        int ans = 0;
        if (c < cap) // that means for that bus i can still find the ans
            ans = b[n - 1];
        else
            ans = p[j - 1];

        // now we have to find the largest number which is not in p and less than ans
        for (int i = j - 1; i >= 0; i--)
        {
            if (ans == p[i])
                ans--;
            else
                break;
        }
        return ans;
    }
};