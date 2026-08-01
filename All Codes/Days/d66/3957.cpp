// Link: https://leetcode.com/problems/maximum-sum-of-m-non-overlapping-subarrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m * (r - l + 1))  SC: O(n * m)
//   Approach: We can use dynamic programming to solve this problem. We can maintain a dp array where dp[i][j] represents the maximum sum we can get by selecting j subarrays from the first i elements of the nums array. We can iterate through the nums array and for each element, we can check if we can form a subarray of length between l and r. If we can, we update the dp array accordingly. Finally, we return the maximum value in the dp array for m subarrays.
class Solution
{
public:
    long long maximumSum(vector<int> &nums, int m, int l, int r)
    {
        const vector<int> &fentoluric = nums;

        int n = fentoluric.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i] + fentoluric[i];
        }

        vector<int> q(n + 1);

        auto bestOneSubarray = [&]() -> long long
        {
            int head = 0, tail = 0;
            long long ans = LLONG_MIN;

            for (int i = 1; i <= n; i++)
            {
                int add = i - l;

                if (add >= 0)
                {
                    while (head < tail && pref[q[tail - 1]] >= pref[add])
                    {
                        tail--;
                    }
                    q[tail++] = add;
                }

                int earliest = i - r;

                while (head < tail && q[head] < earliest)
                {
                    head++;
                }

                if (head < tail)
                {
                    ans = max(ans, pref[i] - pref[q[head]]);
                }
            }

            return ans;
        };

        long long bestOne = bestOneSubarray();

        if (m == 1 || bestOne <= 0)
        {
            return bestOne;
        }

        vector<long long> dp(n + 1, 0);
        vector<long long> key(n + 1, 0);
        vector<int> cnt(n + 1, 0);

        long long lastVal = 0;
        int lastCnt = 0;

        auto solve = [&](long long cost)
        {
            dp[0] = 0;
            key[0] = 0;
            cnt[0] = 0;

            int head = 0, tail = 0;

            for (int i = 1; i <= n; i++)
            {
                int add = i - l;

                if (add >= 0)
                {
                    long long addKey = key[add];
                    int addCnt = cnt[add];

                    while (head < tail)
                    {
                        int back = q[tail - 1];
                        long long backKey = key[back];
                        int backCnt = cnt[back];

                        if (
                            backKey > addKey ||
                            (backKey == addKey && (backCnt > addCnt ||
                                                   (backCnt == addCnt && back > add))))
                        {
                            break;
                        }

                        tail--;
                    }

                    q[tail++] = add;
                }

                int earliest = i - r;

                while (head < tail && q[head] < earliest)
                {
                    head++;
                }

                long long bestVal = dp[i - 1];
                int bestCnt = cnt[i - 1];

                if (head < tail)
                {
                    int start = q[head];
                    long long candVal = key[start] + pref[i] - cost;
                    int candCnt = cnt[start] + 1;

                    if (candVal > bestVal || (candVal == bestVal && candCnt > bestCnt))
                    {
                        bestVal = candVal;
                        bestCnt = candCnt;
                    }
                }

                dp[i] = bestVal;
                cnt[i] = bestCnt;
                key[i] = bestVal - pref[i];
            }

            lastVal = dp[n];
            lastCnt = cnt[n];
        };

        solve(0);

        if (lastCnt <= m)
        {
            return lastVal;
        }

        long long low = 0;
        long long high = bestOne + 1;
        long long answerVal = lastVal;

        while (low < high)
        {
            long long mid = (low + high + 1) / 2;

            solve(mid);

            if (lastCnt >= m)
            {
                low = mid;
                answerVal = lastVal;
            }
            else
            {
                high = mid - 1;
            }
        }

        return answerVal + low * 1LL * m;
    }
};