// Link: https://leetcode.com/problems/largest-component-size-by-common-factor/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * sqrt(maxVal) * alpha(n))  SC: O(n + maxVal)
// Approach: union-find over indices, where each number is unioned with
// all others sharing a prime factor. For each num, factorize it and
// union its index with the index that first introduced each prime
// factor (tracked via a prime-> first-index map). Finally count the
// largest component size.
class Solution {
    vector<int> parent, size_;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (size_[a] < size_[b]) swap(a, b);
        parent[b] = a;
        size_[a] += size_[b];
    }
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        size_.assign(n, 1);

        unordered_map<int,int> primeFirstIndex;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int p = 2; (long long)p * p <= x; p++) {
                if (x % p == 0) {
                    if (primeFirstIndex.count(p)) unite(i, primeFirstIndex[p]);
                    else primeFirstIndex[p] = i;
                    while (x % p == 0) x /= p;
                }
            }
            if (x > 1) {
                if (primeFirstIndex.count(x)) unite(i, primeFirstIndex[x]);
                else primeFirstIndex[x] = i;
            }
        }

        int best = 0;
        for (int i = 0; i < n; i++) best = max(best, size_[find(i)]);
        return best;
    }
};
