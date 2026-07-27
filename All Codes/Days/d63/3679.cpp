// Link: https://leetcode.com/problems/minimum-discards-to-balance-inventory/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: sliding window over the last w ORIGINAL positions (kept or
// not). For each arrival, first evict kept items that fell out of the
// window [i-w+1, i], then check the current count of this type within
// the window: if still below m, keep it (add to window); otherwise
// discard it.
class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        unordered_map<int,int> count;
        deque<pair<int,int>> window; // (position, type)
        int discards = 0;

        for (int i = 0; i < n; i++) {
            while (!window.empty() && window.front().first < i - w + 1) {
                count[window.front().second]--;
                window.pop_front();
            }
            int type = arrivals[i];
            if (count[type] < m) {
                count[type]++;
                window.push_back({i, type});
            } else {
                discards++;
            }
        }
        return discards;
    }
};
