// Link: https://leetcode.com/problems/rearranging-fruits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> freq1, freq2;
        for (int x : basket1) freq1[x]++;
        for (int x : basket2) freq2[x]++;

        int minOverall = INT_MAX;
        for (int x : basket1) minOverall = min(minOverall, x);
        for (int x : basket2) minOverall = min(minOverall, x);

        unordered_set<int> allVals;
        for (auto &[v,c] : freq1) allVals.insert(v);
        for (auto &[v,c] : freq2) allVals.insert(v);

        vector<int> toSwap;
        for (int v : allVals) {
            int total = freq1[v] + freq2[v];
            if (total % 2 != 0) return -1;
            int diff = abs(freq1[v] - freq2[v]);
            for (int i = 0; i < diff / 2; i++) toSwap.push_back(v);
        }

        sort(toSwap.begin(), toSwap.end());
        long long cost = 0;
        for (int i = 0; i < (int)toSwap.size() / 2; i++) {
            cost += min(toSwap[i], 2 * minOverall);
        }
        return cost;
    }
};
