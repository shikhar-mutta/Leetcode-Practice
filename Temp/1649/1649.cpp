// Link: https://leetcode.com/problems/create-sorted-array-through-instructions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bit;
    int N;

    void update(int i) {
        for (; i <= N; i += i & (-i)) bit[i]++;
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & (-i)) s += bit[i];
        return s;
    }

    int createSortedArray(vector<int>& instructions) {
        N = 100001;
        bit.assign(N + 1, 0);
        const long long MOD = 1e9 + 7;
        long long cost = 0;
        for (int i = 0; i < (int)instructions.size(); i++) {
            int x = instructions[i];
            int less = query(x - 1);
            int greater = i - query(x);
            cost = (cost + min(less, greater)) % MOD;
            update(x);
        }
        return (int)cost;
    }
};
