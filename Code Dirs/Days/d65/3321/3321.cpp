// Link: https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N log N), SC: O(N)
// Approach: sliding window maintaining a frequency map plus two ordered sets of (freq,value)
// pairs — "top" holds the x largest (by freq then value), "rest" holds everything else, with a
// running sum over "top". Adding/removing an element's frequency relocates its pair and
// rebalances (promote rest's max into top if top is short, or swap if rest's max now outranks
// top's min) so top always reflects the current x-sum candidates in O(log N) per window step.
class Solution {
public:
    unordered_map<int,int> freq;
    set<pair<int,int>> top, rest;
    long long sumTop = 0;
    int X;

    void moveToRest(pair<int,int> p) {
        top.erase(p);
        sumTop -= (long long)p.first * p.second;
        rest.insert(p);
    }
    void moveToTop(pair<int,int> p) {
        rest.erase(p);
        top.insert(p);
        sumTop += (long long)p.first * p.second;
    }

    void rebalance() {
        while ((int)top.size() < X && !rest.empty()) moveToTop(*rest.rbegin());
        while (!rest.empty() && !top.empty() && *rest.rbegin() > *top.begin()) {
            auto biggestRest = *rest.rbegin();
            auto smallestTop = *top.begin();
            moveToRest(smallestTop);
            moveToTop(biggestRest);
        }
    }

    void removePair(int v) {
        int old = freq[v];
        if (old > 0) {
            pair<int,int> p = {old, v};
            if (top.count(p)) { top.erase(p); sumTop -= (long long)old * v; }
            else rest.erase(p);
        }
    }
    void insertPair(int v) {
        int f = freq[v];
        if (f > 0) rest.insert({f, v});
    }

    void addValue(int v) {
        removePair(v);
        freq[v]++;
        insertPair(v);
        rebalance();
    }
    void removeValue(int v) {
        removePair(v);
        freq[v]--;
        insertPair(v);
        rebalance();
    }

    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        X = x;
        int n = nums.size();
        vector<long long> ans;
        for (int i = 0; i < n; i++) {
            addValue(nums[i]);
            if (i >= k) removeValue(nums[i-k]);
            if (i >= k-1) ans.push_back(sumTop);
        }
        return ans;
    }
};
