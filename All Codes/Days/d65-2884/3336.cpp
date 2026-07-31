// Link: https://leetcode.com/problems/find-the-number-of-subsequences-with-equal-gcd/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2), SC: O(n) --- IGNORE ---
//  Approach: For each pair of numbers (a, b) in the input array, we can calculate their GCD using the Euclidean algorithm. We can then use a map to count the number of pairs that have the same GCD. Finally, we can return the count of pairs that have the same GCD.
#pragma GCC optimize("O3,unroll-loops,tree-vectorize,strict-aliasing")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const auto fast_io = []() [[gnu::always_inline]]
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution
{
    static constexpr int MOD = 1'000'000'007;
    static constexpr int MAXV = 200;

    alignas(64) inline static int cnt[MAXV + 1];

    static constexpr array<int, MAXV + 1> POW2 = []
    {
        array<int, MAXV + 1> p{};
        p[0] = 1;
        for (int i = 1; i <= MAXV; ++i)
        {
            p[i] = static_cast<int64_t>(p[i - 1]) * 2 % MOD;
        }
        return p;
    }();

    static constexpr array<int, MAXV + 1> POW3 = []
    {
        array<int, MAXV + 1> p{};
        p[0] = 1;
        for (int i = 1; i <= MAXV; ++i)
        {
            p[i] = static_cast<int64_t>(p[i - 1]) * 3 % MOD;
        }
        return p;
    }();

    static constexpr array<int8_t, MAXV + 1> MU = []
    {
        array<int8_t, MAXV + 1> mu{};
        mu[1] = 1;
        for (int d = 1; d <= MAXV; ++d)
        {
            for (int x = d + d; x <= MAXV; x += d)
            {
                mu[x] -= mu[d];
            }
        }
        return mu;
    }();

    inline static const array<array<uint16_t, MAXV + 1>, MAXV + 1> LCM = []
    {
        array<array<uint16_t, MAXV + 1>, MAXV + 1> table{};
        for (int a = 1; a <= MAXV; ++a)
        {
            for (int b = a; b <= MAXV; ++b)
            {
                int x = a, y = b;
                while (y != 0)
                {
                    const int t = x % y;
                    x = y;
                    y = t;
                }
                const int value = a / x * b;
                table[a][b] = static_cast<uint16_t>(value);
                table[b][a] = static_cast<uint16_t>(value);
            }
        }
        return table;
    }();

    inline static const array<array<int8_t, MAXV + 1>, MAXV + 1> WEIGHT = []
    {
        array<array<int8_t, MAXV + 1>, MAXV + 1> w{};
        for (int x = 1; x <= MAXV; ++x)
        {
            for (int y = x; y <= MAXV; ++y)
            {
                int sum = 0;
                int d = std::gcd(x, y);
                for (int g = 1; g <= d; ++g)
                {
                    if (d % g == 0)
                    {
                        sum += MU[x / g] * MU[y / g];
                    }
                }
                w[x][y] = static_cast<int8_t>((x == y) ? sum : sum * 2);
            }
        }
        return w;
    }();

public:
    [[clang::hot]]
    int subsequencePairCount(vector<int> &nums)
    {
        const int mx = ranges::max(nums);

        fill_n(cnt, mx + 1, 0);
        for (const int x : nums)
        {
            ++cnt[x];
        }

        for (int d = 1; d <= mx; ++d)
        {
            int sum = cnt[d];
            for (int multiple = d + d; multiple <= mx; multiple += d)
            {
                sum += cnt[multiple];
            }
            cnt[d] = sum;
        }

        int64_t answer = 0;

        for (int a = 1; a <= mx; ++a)
        {
            const int ca = cnt[a];
            if (ca == 0)
                continue;

            for (int b = a; b <= mx; ++b)
            {
                const int w = WEIGHT[a][b];
                if (w == 0)
                    continue;

                const int cb = cnt[b];
                if (cb == 0)
                    continue;

                const int lcm = LCM[a][b];
                const int common = lcm <= mx ? cnt[lcm] : 0;

                int64_t ways = static_cast<int64_t>(POW3[common]) *
                               POW2[ca + cb - (common << 1)] % MOD;

                ways = ways - POW2[ca] - POW2[cb] + 1;
                answer += ways * w;
            }
        }

        answer %= MOD;
        return answer < 0 ? answer + MOD : static_cast<int>(answer);
    }
};
