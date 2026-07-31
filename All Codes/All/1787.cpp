// Link: https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log n + k * 1024)  SC: O(1024)
//  Approach: group indices by i%k. dp[x] = min changes over processed groups
//  so that xor of chosen values equals x. For each group, default option is
//  "change everything" (min(dp) + groupSize), then improve using each distinct
//  value present in the group (keep unchanged elements of that value).
class Solution
{
    constexpr static int NMAX = (1 << 10);
    constexpr static int LARGE_NUM = (1 << 30);

public:
    int minChanges(vector<int> &nums, int k)
    {
        std::vector<std::array<int, NMAX>> storage(k, std::array<int, NMAX>{});
        const int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            storage[i % k][nums[i]]++;
        }
        std::array<int, NMAX> dp{};
        dp.fill(LARGE_NUM);
        std::array<int, NMAX> dp2{};
        dp2.fill(LARGE_NUM);
        dp2[0] = 0;
        for (int i = 0; i < k; i++)
        {
            int total = n / k + ((i < (n % k)) ? 1 : 0);
            auto it = *std::ranges::min_element(dp2);
            dp.fill(total + it);
            for (int j = 0; j < NMAX; j++)
            {
                if (storage[i][j] == 0)
                    continue;
                for (int curr = 0; curr < NMAX; curr++)
                {
                    dp[j ^ curr] = min(dp[j ^ curr], total - storage[i][j] + dp2[curr]);
                }
            }
            for (int j = 0; j < NMAX; j++)
                dp2[j] = dp[j];
        }
        return dp[0];
    }
};