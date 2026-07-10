// Link: https://leetcode.com/problems/3sum-with-multiplicity/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumMulti(vector<int> &arr, int target)
    {
        const long long MOD = 1e9 + 7;
        array<long long, 101> cnt{};
        for (int x : arr)
            cnt[x]++;

        long long ans = 0;
        for (int x = 0; x <= 100; x++)
        {
            for (int y = x; y <= 100; y++)
            {
                int z = target - x - y;
                if (z < y || z > 100)
                    continue;
                if (x == y && y == z)
                    ans += cnt[x] * (cnt[x] - 1) * (cnt[x] - 2) / 6;
                else if (x == y)
                    ans += cnt[x] * (cnt[x] - 1) / 2 * cnt[z];
                else if (y == z)
                    ans += cnt[x] * (cnt[y] * (cnt[y] - 1) / 2);
                else
                    ans += cnt[x] * cnt[y] * cnt[z];
                ans %= MOD;
            }
        }
        return ans;
    }
};
