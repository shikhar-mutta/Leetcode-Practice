// Link: https://leetcode.com/problems/gcd-sort-of-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> parent;
    int find(int x) {
        while (parent[x] != x) { parent[x] = parent[parent[x]]; x = parent[x]; }
        return x;
    }
    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra != rb) parent[ra] = rb;
    }

    bool gcdSort(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        vector<int> spf(maxVal + 1, 0);
        for (int i = 2; i <= maxVal; i++) {
            if (spf[i] == 0) {
                for (int j = i; j <= maxVal; j += i) {
                    if (spf[j] == 0) spf[j] = i;
                }
            }
        }

        parent.resize(maxVal + 1);
        iota(parent.begin(), parent.end(), 0);

        for (int x : nums) {
            int v = x;
            while (v > 1) {
                int p = spf[v];
                unite(x, p);
                while (v % p == 0) v /= p;
            }
        }

        vector<int> sorted_ = nums;
        sort(sorted_.begin(), sorted_.end());
        for (int i = 0; i < (int)nums.size(); i++) {
            if (find(nums[i]) != find(sorted_[i])) return false;
        }
        return true;
    }
};
