// Link: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        unordered_set<int> prev;
        int best = INT_MAX;
        for (int x : arr) {
            unordered_set<int> cur;
            cur.insert(x);
            for (int p : prev) cur.insert(p & x);
            for (int v : cur) best = min(best, abs(v - target));
            prev = cur;
        }
        return best;
    }
};
