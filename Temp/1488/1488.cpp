// Link: https://leetcode.com/problems/avoid-flood-in-the-city/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, -1);
        unordered_map<int,int> fullLake;
        set<int> dryDays;

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
                res[i] = 1;
            } else {
                int lake = rains[i];
                res[i] = -1;
                if (fullLake.count(lake)) {
                    auto it = dryDays.upper_bound(fullLake[lake]);
                    if (it == dryDays.end()) return {};
                    res[*it] = lake;
                    dryDays.erase(it);
                }
                fullLake[lake] = i;
            }
        }
        return res;
    }
};
