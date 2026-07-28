// Link: https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        int ans = INT_MAX;
        vector<int> prev;
        for (int x : arr) {
            vector<int> cur;
            cur.push_back(x);
            for (int p : prev) cur.push_back(p & x);
            sort(cur.begin(), cur.end());
            cur.erase(unique(cur.begin(), cur.end()), cur.end());
            for (int v : cur) ans = min(ans, abs(v - target));
            prev = cur;
        }
        return ans;
    }
};
