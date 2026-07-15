// Link: https://leetcode.com/problems/maximum-ice-cream-bars/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int r = *max_element(costs.begin(), costs.end());
        vector<int> freq(r + 1);
        for (int i : costs)
        {
            freq[i]++;
        }
        int c = 0;
        int l = 1;
        while (l <= r && coins > 0)
        {
            while (l <= r && freq[l] == 0)
            {
                l++;
            }
            if (l > r)
                break;
            if ((coins -= l) >= 0)
            {
                c++;
                freq[l]--;
            }
        }
        return c;
    }
};