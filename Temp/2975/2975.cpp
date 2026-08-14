// Link: https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1); hFences.push_back(m);
        vFences.push_back(1); vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hDiffs;
        for (int i = 0; i < (int)hFences.size(); i++)
            for (int j = i + 1; j < (int)hFences.size(); j++)
                hDiffs.insert(hFences[j] - hFences[i]);

        int best = -1;
        for (int i = 0; i < (int)vFences.size(); i++) {
            for (int j = i + 1; j < (int)vFences.size(); j++) {
                int d = vFences[j] - vFences[i];
                if (hDiffs.count(d)) best = max(best, d);
            }
        }
        if (best == -1) return -1;
        const long long MOD = 1e9 + 7;
        return (int)((long long)best * best % MOD);
    }
};
