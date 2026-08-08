// Link: https://leetcode.com/problems/maximize-the-beauty-of-the-garden/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        int n = flowers.size();
        vector<long long> prefixPos(n, 0);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            prefixPos[i] = (i > 0 ? prefixPos[i-1] : 0) + max(flowers[i], 0);
            total += flowers[i];
        }

        unordered_map<int, int> firstIdx;
        long long best = total;
        for (int j = 0; j < n; j++) {
            if (firstIdx.count(flowers[j])) {
                int i = firstIdx[flowers[j]];
                long long interior = prefixPos[j-1] - (i >= 0 ? prefixPos[i] : 0);
                long long candidate = interior + flowers[i] + flowers[j];
                best = max(best, candidate);
            } else {
                firstIdx[flowers[j]] = j;
            }
        }
        return (int)best;
    }
};
