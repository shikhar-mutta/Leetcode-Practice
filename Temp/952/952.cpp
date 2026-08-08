// Link: https://leetcode.com/problems/largest-component-size-by-common-factor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);
        function<int(int)> find = [&](int x) {
            while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
            return x;
        };
        auto unite = [&](int a, int b) {
            int ra = find(a), rb = find(b);
            if (ra != rb) parent[ra] = rb;
        };

        unordered_map<int,int> primeToIdx;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p = 2; (long long)p * p <= x; p++) {
                if (x % p == 0) {
                    if (primeToIdx.count(p)) unite(i, primeToIdx[p]);
                    else primeToIdx[p] = i;
                    while (x % p == 0) x /= p;
                }
            }
            if (x > 1) {
                if (primeToIdx.count(x)) unite(i, primeToIdx[x]);
                else primeToIdx[x] = i;
            }
        }

        unordered_map<int,int> sizeCnt;
        int best = 0;
        for (int i = 0; i < n; i++) {
            int r = find(i);
            best = max(best, ++sizeCnt[r]);
        }
        return best;
    }
};
