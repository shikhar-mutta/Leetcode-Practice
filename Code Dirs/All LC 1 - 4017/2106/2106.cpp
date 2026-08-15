// Link: https://leetcode.com/problems/maximum-fruits-harvested-after-at-most-k-steps/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cost(int Lp, int Rp, int startPos) {
        if (Rp <= startPos) return startPos - Lp;
        if (Lp >= startPos) return Rp - startPos;
        return min(2 * (startPos - Lp) + (Rp - startPos), 2 * (Rp - startPos) + (startPos - Lp));
    }

    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int l = 0;
        long long sum = 0;
        int best = 0;
        for (int r = 0; r < n; r++) {
            sum += fruits[r][1];
            while (l <= r && cost(fruits[l][0], fruits[r][0], startPos) > k) {
                sum -= fruits[l][1];
                l++;
            }
            best = max(best, (int)sum);
        }
        return best;
    }
};
