// Link: https://leetcode.com/problems/knight-dialer/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the number of hops.
// SC: O(n), where n is the number of hops.
// Approach:
// 1. We will use dynamic programming to solve this problem.
// 2. We will create a 2D array dp[n][10] where dp[i][j] will store the number of distinct phone numbers of length i that can be dialed starting from digit j.
// 3. We will initialize dp[1][j] = 1 for all j from 0 to 9, since there is only one way to dial a number of length 1 starting from any digit.
// 4. We will then fill the dp array using the next array which stores the possible moves of the knight from each digit.
// 5. Finally, we will return the sum of dp[n][j] for all j from 0 to 9, which will give us the total number of distinct phone numbers of length n that can be dialed starting from any digit.
// Note: We will take the modulo of the answer with 10^9 + 7 to avoid overflow.
typedef long long ll;
const ll mod = 1e9 + 7;
class Solution
{
public:
    static inline bool flag = true;
    const vector<vector<int>> next = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    static inline vector<vector<ll>> p =
        vector<vector<ll>>(5001, vector<ll>(10, 0));

    void init()
    {
        flag = false;
        int k, i;
        p[1].assign(10, 1);
        for (k = 0; k < 10; k++)
            p[2][k] = next[k].size();
        for (i = 3; i <= 5000; i++)
        {
            for (k = 0; k < 10; k++)
            {
                for (auto kj : next[k])
                    p[i][k] = (p[i][k] + p[i - 1][kj]) % mod;
            }
        }
    }

    int knightDialer(int n)
    {
        if (flag)
            init();
        ll ans = 0LL;
        for (int k = 0; k < 10; k++)
            ans = (ans + p[n][k]) % mod;
        return ans;
    }
};
