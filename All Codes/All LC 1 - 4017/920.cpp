// Link: https://leetcode.com/problems/number-of-music-playlists/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n * goal)  SC: O(n * goal)
// Approach: dp[i][j] = number of playlists of length i using exactly j
// distinct songs. Transition: either play a brand-new song (n-(j-1)
// choices from dp[i-1][j-1]), or replay an already-used song that isn't
// among the last k played (j-k choices, valid only if j>k), from
// dp[i-1][j].
class Solution
{
public:
    using ll = long long;

    int mod = 1e9 + 7;
    int n, goal, k;

    ll dp[101][101];

    ll solve(int cnt_songs, int cnt_unique)
    {

        if (cnt_songs == goal)
            return cnt_unique == n;

        if (dp[cnt_songs][cnt_unique] != -1)
            return dp[cnt_songs][cnt_unique];

        ll res = 0;

        // Play a new unique song.
        if (cnt_unique < n)
        {
            res = (res + 1LL * (n - cnt_unique) *
                             solve(cnt_songs + 1, cnt_unique + 1)) %
                  mod;
        }

        // Replay an old song.
        if (cnt_unique > k)
        {
            res = (res +
                   1LL * (cnt_unique - k) * solve(cnt_songs + 1, cnt_unique)) %
                  mod;
        }

        return dp[cnt_songs][cnt_unique] = res;
    }

    int numMusicPlaylists(int n, int goal, int k)
    {

        this->n = n;
        this->goal = goal;
        this->k = k;

        memset(dp, -1, sizeof(dp));

        return solve(0, 0);
    }
};