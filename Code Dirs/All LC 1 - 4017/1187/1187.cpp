// Link: https://leetcode.com/problems/make-array-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        const int INF = INT_MAX / 2;
        map<long long, int> dp;
        dp[-1LL] = 0;

        for (int x : arr1) {
            map<long long, int> ndp;
            for (auto& [last, ops] : dp) {
                if (x > last) {
                    long long key = x;
                    if (!ndp.count(key) || ndp[key] > ops) ndp[key] = ops;
                }
                auto it = upper_bound(arr2.begin(), arr2.end(), last);
                if (it != arr2.end()) {
                    long long key = *it;
                    int nops = ops + 1;
                    if (!ndp.count(key) || ndp[key] > nops) ndp[key] = nops;
                }
            }
            dp = ndp;
            if (dp.empty()) return -1;
        }

        int best = INF;
        for (auto& [last, ops] : dp) best = min(best, ops);
        return best == INF ? -1 : best;
    }
};
