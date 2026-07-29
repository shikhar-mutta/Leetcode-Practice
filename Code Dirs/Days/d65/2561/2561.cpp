// Link: https://leetcode.com/problems/rearranging-fruits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: for each value, count1-count2 must be even (else impossible). Collect half the
// excess of each imbalanced value into one list (the fruits that must effectively leave their
// basket), sort it, and for the smaller half swap; the cost to "move" a fruit of value x is
// min(x, 2*globalMin) since a real swap can be simulated cheaply by round-tripping the cheapest
// fruit in the whole collection. Sum costs over the size/2 cheapest excess fruits.
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int> cnt1, cnt2;
        int globalMin = INT_MAX;
        for (int x : basket1) { cnt1[x]++; globalMin = min(globalMin, x); }
        for (int x : basket2) { cnt2[x]++; globalMin = min(globalMin, x); }

        vector<int> excess;
        unordered_set<int> keys;
        for (auto& [k,v] : cnt1) keys.insert(k);
        for (auto& [k,v] : cnt2) keys.insert(k);

        for (int v : keys) {
            int c1 = cnt1.count(v) ? cnt1[v] : 0;
            int c2 = cnt2.count(v) ? cnt2[v] : 0;
            int diff = c1 - c2;
            if (diff % 2 != 0) return -1;
            int half = abs(diff) / 2;
            for (int i = 0; i < half; i++) excess.push_back(v);
        }

        sort(excess.begin(), excess.end());
        long long ans = 0;
        int half = excess.size() / 2;
        for (int i = 0; i < half; i++) ans += min(excess[i], 2 * globalMin);
        return ans;
    }
};
