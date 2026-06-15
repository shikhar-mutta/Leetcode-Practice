// Link: https://leetcode.com/problems/avoid-flood-in-the-city/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n = rains.size();
        vector<int> ans(n, 1);        // default for dry days; rainy days set to -1
        unordered_map<int, int> full; // lake -> last day it was filled
        set<int> dry;                 // indices of dry days available to use

        for (int i = 0; i < n; ++i)
        {
            if (rains[i] == 0)
            {
                dry.insert(i); // a dry day we can spend later
                continue;
            }
            ans[i] = -1; // it rains, can't dry today
            int lake = rains[i];
            auto it = full.find(lake);
            if (it != full.end())
            { // lake already full -> must have dried it in between
                // earliest dry day strictly after this lake was filled
                auto d = dry.upper_bound(it->second);
                if (d == dry.end())
                    return {};  // no dry day available -> flood
                ans[*d] = lake; // dry this lake on that day
                dry.erase(d);
            }
            full[lake] = i; // (re)fill the lake today
        }
        return ans;
    }
};
