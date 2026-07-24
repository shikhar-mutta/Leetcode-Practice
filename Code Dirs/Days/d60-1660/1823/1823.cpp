// Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    // Approach: Josephus Problem
    // 1. We can solve this problem using the Josephus problem formula.
    // 2. The Josephus problem is a theoretical problem related to a certain counting-out game
    // 3. The problem can be solved using a recursive formula or an iterative approach.
    int findTheWinner(int n, int k)
    {
        int res = 0;
        for (int i = 2; i <= n; ++i)
            res = (res + k) % i;
        return res + 1;
    }
};