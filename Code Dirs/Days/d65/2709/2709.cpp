// Link: https://leetcode.com/problems/greatest-common-divisor-traversal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N sqrt(maxVal) alpha(N)), SC: O(N)
// Approach: DSU over indices; for each prime factor, union the current index with the first
// index seen having that prime (two numbers sharing a prime factor have gcd>1, so are
// traversable). All indices must end up in one component (a value of 1 with n>1 is isolated).
class Solution {
public:
    vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    void unite(int a, int b) { a = find(a); b = find(b); if (a != b) parent[a] = b; }

    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        unordered_map<int,int> primeFirst;
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            if (x == 1) return false;
            for (int p = 2; (long long)p * p <= x; p++) {
                if (x % p == 0) {
                    while (x % p == 0) x /= p;
                    if (primeFirst.count(p)) unite(i, primeFirst[p]);
                    else primeFirst[p] = i;
                }
            }
            if (x > 1) {
                if (primeFirst.count(x)) unite(i, primeFirst[x]);
                else primeFirst[x] = i;
            }
        }

        int root = find(0);
        for (int i = 1; i < n; i++) if (find(i) != root) return false;
        return true;
    }
};
