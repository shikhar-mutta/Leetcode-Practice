// Link: https://leetcode.com/problems/create-sorted-array-through-instructions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> bit;
    int n;
    void update(int i) { for (; i <= n; i += i & (-i)) bit[i]++; }
    int query(int i) { int s = 0; for (; i > 0; i -= i & (-i)) s += bit[i]; return s; }
public:
    int createSortedArray(vector<int>& instructions) {
        n = 100000;
        bit.assign(n + 1, 0);
        const long long MOD = 1e9 + 7;
        long long cost = 0;
        int cnt = 0;
        for (int x : instructions) {
            int less = query(x - 1);
            int leq = query(x);
            int greater = cnt - leq;
            cost += min(less, greater);
            update(x);
            cnt++;
        }
        return (int)(cost % MOD);
    }
};
