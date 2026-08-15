// Link: https://leetcode.com/problems/greatest-common-divisor-traversal/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int,int> parent;
    int find(int x) {
        if (!parent.count(x)) parent[x] = x;
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        for (int x : nums) {
            if (x == 1) return false;
            int v = x;
            for (int p = 2; (long long)p * p <= v; p++) {
                if (v % p == 0) {
                    unite(x, -p);
                    while (v % p == 0) v /= p;
                }
            }
            if (v > 1) unite(x, -v);
        }

        int root = find(nums[0]);
        for (int x : nums) if (find(x) != root) return false;
        return true;
    }
};
