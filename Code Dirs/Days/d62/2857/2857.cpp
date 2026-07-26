// Link: https://leetcode.com/problems/count-pairs-of-points-with-distance-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*k)
// SC: O(n)
// Approach: (x1^x2)+(y1^y2)==k means for a fixed split a (0..k) of k's bits
// between the two XOR terms, a partner point would be (x^a, y^(k-a)). For
// each new point, check how many previously-seen points match each of the
// k+1 possible partner coordinates (encoded into a single map key), then add
// the current point to the map.
class Solution {
public:
    int countPairs(vector<vector<int>>& v, int k) {
        unordered_map<long long, int> mp; // encoded (x,y) -> count
        long long ans = 0;
        for (auto& p : v) {
            int x = p[0], y = p[1];
            for (int a = 0; a <= k; a++) {
                int nx = x ^ a, ny = y ^ (k - a);
                long long key =
                    (long long)nx * 1000001 + ny; // encode partner coords
                auto it = mp.find(key);
                if (it != mp.end())
                    ans += it->second;
            }
            mp[(long long)x * 1000001 + y]++; // encode & insert current
        }
        return ans;
    }
};
