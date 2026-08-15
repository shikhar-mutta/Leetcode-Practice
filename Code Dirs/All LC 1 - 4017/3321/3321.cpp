// Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,int> freq;
    unordered_set<int> inTop;
    multiset<pair<int,int>, greater<pair<int,int>>> top, rest;
    long long topSum = 0;
    int X;

    void rebalance() {
        while ((int)top.size() < X && !rest.empty()) {
            auto it = rest.begin();
            auto pr = *it;
            rest.erase(it);
            top.insert(pr);
            inTop.insert(pr.second);
            topSum += (long long)pr.first * pr.second;
        }
        while (!rest.empty() && !top.empty()) {
            auto bestRest = *rest.begin();
            auto worstTop = *top.rbegin();
            if (bestRest > worstTop) {
                rest.erase(rest.begin());
                top.erase(prev(top.end()));
                topSum -= (long long)worstTop.first * worstTop.second;
                inTop.erase(worstTop.second);
                top.insert(bestRest);
                inTop.insert(bestRest.second);
                topSum += (long long)bestRest.first * bestRest.second;
                rest.insert(worstTop);
            } else break;
        }
    }

    void updateFreq(int v, int delta) {
        int oldFreq = freq[v];
        if (oldFreq > 0) {
            if (inTop.count(v)) {
                top.erase({oldFreq, v});
                topSum -= (long long)oldFreq * v;
                inTop.erase(v);
            } else {
                rest.erase({oldFreq, v});
            }
        }
        int newFreq = oldFreq + delta;
        freq[v] = newFreq;
        if (newFreq > 0) {
            rest.insert({newFreq, v});
        }
        rebalance();
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        freq.clear(); inTop.clear(); top.clear(); rest.clear(); topSum = 0;
        X = x;
        int n = nums.size();
        vector<long long> res;

        for (int i = 0; i < k; i++) updateFreq(nums[i], 1);
        res.push_back(topSum);

        for (int i = k; i < n; i++) {
            updateFreq(nums[i-k], -1);
            updateFreq(nums[i], 1);
            res.push_back(topSum);
        }

        return res;
    }
};
