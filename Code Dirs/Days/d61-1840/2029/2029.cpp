// Link: https://leetcode.com/problems/stone-game-ix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach:
//  1. We can count the number of stones with remainder 0, 1, and 2 when divided by 3.
//  2. If there are no stones with remainder 1 or 2, then Alice cannot make a move and Bob wins.
//  3
class Solution
{
public:
    bool stoneGameIX(vector<int> &stones)
    {
        int cnt[3] = {0};
        for (int i = 0, n = stones.size(); i < n; ++i)
            ++cnt[stones[i] % 3];
        int zero = cnt[0], one = cnt[1], two = cnt[2];
        if (min(one, two) == 0)
            return max(one, two) > 2 && (zero & 1);
        return zero % 2 == 0 || abs(two - one) > 2;
    }
};