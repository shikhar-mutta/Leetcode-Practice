// Link: https://leetcode.com/problems/find-subarray-with-bitwise-or-closest-to-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int best = INT_MAX;
        vector<int> prev;
        for (int x : nums) {
            vector<int> cur = {x};
            for (int p : prev) cur.push_back(p | x);
            sort(cur.begin(), cur.end());
            cur.erase(unique(cur.begin(), cur.end()), cur.end());
            for (int v : cur) best = min(best, abs(v - k));
            prev = cur;
        }
        return best;
    }
};
