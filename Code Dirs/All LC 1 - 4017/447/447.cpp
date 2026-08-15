// Link: https://leetcode.com/problems/number-of-boomerangs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: for each point, count distances to every other point; for each
// distance group of size k, k*(k-1) ordered pairs form valid boomerangs
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int total = 0;
        for (auto& p : points) {
            unordered_map<long long, int> distCount;
            for (auto& q : points) {
                if (&p == &q) continue;
                long long dx = p[0] - q[0], dy = p[1] - q[1];
                distCount[dx*dx + dy*dy]++;
            }
            for (auto& [d, cnt] : distCount) total += cnt * (cnt - 1);
        }
        return total;
    }
};
