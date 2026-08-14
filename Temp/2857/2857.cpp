// Link: https://leetcode.com/problems/count-pairs-of-points-with-distance-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        map<pair<int,int>, int> seen;
        int ans = 0;
        for (auto& c : coordinates) {
            int x = c[0], y = c[1];
            for (int a = 0; a <= k; a++) {
                int b = k - a;
                int nx = x ^ a, ny = y ^ b;
                auto it = seen.find({nx, ny});
                if (it != seen.end()) ans += it->second;
            }
            seen[{x, y}]++;
        }
        return ans;
    }
};
