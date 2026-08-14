// Link: https://leetcode.com/problems/find-number-of-ways-to-reach-the-k-th-stair/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long k;
    map<tuple<long long,int,bool>, long long> memo;

    long long dfs(long long i, int jump, bool canDown) {
        if (jump > 32 || i > (long long)k + (1LL << 32)) return (i == k) ? 1 : 0;
        auto key = make_tuple(i, jump, canDown);
        auto it = memo.find(key);
        if (it != memo.end()) return it->second;
        long long total = (i == k) ? 1 : 0;
        if (canDown && i > 0) total += dfs(i - 1, jump, false);
        total += dfs(i + (1LL << jump), jump + 1, true);
        memo[key] = total;
        return total;
    }

    int waysToReachStair(int k) {
        this->k = k;
        memo.clear();
        return (int)dfs(1, 0, true);
    }
};
