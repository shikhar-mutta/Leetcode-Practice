// Link: https://leetcode.com/problems/apply-operations-to-maximize-score/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn), SC: O(n)
//  Approach: We can use a greedy approach to find the maximum score. We will first calculate the prime score for each number in the array. Then, we will use a stack to find the number of subarrays that can be formed with each number as the maximum. We will then sort the numbers in descending order and for each number, we will calculate the maximum score by multiplying the number with the number of subarrays that can be formed with it as the maximum and taking the minimum of that and the remaining k. We will keep track of the maximum score and return it at the end.
class Solution
{
public:
    int maximumScore(vector<int> &nums, int k)
    {
        static constexpr int mod{1000000007};
        static array<uint32_t, 100001> a;
        static array<uint32_t, 100001> st;
        static const auto modPow{[](int64_t x, size_t exp) -> int64_t
                                 {
                                     int64_t result{1};
                                     while (exp)
                                     {
                                         if (exp & 1)
                                             result = result * x % mod;

                                         x = x * x % mod;
                                         exp >>= 1;
                                     }
                                     return result;
                                 }};

        const auto n{nums.size()};
        size_t top{0};
        int mx{0};
        st[top] = ~0U;
        for (size_t i{0}; i < n; ++i)
        {
            const auto num{nums[i]};
            if (num > mx)
                mx = num;

            const auto v{primeScore[num]};
            while (top && primeScore[nums[st[top]]] < v)
            {
                --top;
            }
            a[i] = i - st[top];
            st[++top] = i;
        }

        st[top = 0] = n;
        for (size_t i{n - 1}; ~i; --i)
        {
            const auto v{primeScore[nums[i]]};
            while (top && primeScore[nums[st[top]]] <= v)
            {
                --top;
            }
            a[i] *= st[top] - i;
            st[++top] = i;
        }

        auto idx{st | views::take(n)};
        ranges::iota(idx, 0);
        radixSort(nums, st, n, mx);
        int64_t ans{1};
        for (const auto i : idx | views::reverse)
        {
            if (k <= 0)
                break;

            const auto x{nums[i]};
            const auto t{min(a[i], static_cast<uint32_t>(k))};
            ans = ans * modPow(x, t) % mod;
            k -= t;
        }
        return ans;
    }

private:
    inline static const auto primeScore{[]()
                                        {
                                            static constexpr size_t n{100001};
                                            array<uint32_t, n> primeScore{};
                                            primeScore[1] = 0;
                                            for (size_t i{2}; i < n; ++i)
                                            {
                                                if (primeScore[i])
                                                    continue;

                                                for (size_t j{i}; j < n; j += i)
                                                {
                                                    ++primeScore[j];
                                                }
                                            }
                                            return primeScore;
                                        }()};

    static void radixSort(vector<int> &nums, array<uint32_t, 100001> &idx, size_t n, uint32_t mx)
    {
        static array<tuple<uint32_t *, uint32_t *, uint32_t>, 32> st;
        const auto begin{idx.data()};
        const auto end{begin + n};
        auto r{end};

        size_t stSize{0};

        if (begin + 1 < r)
            st[stSize++] = {begin, r, bit_floor(mx)};

        while (stSize)
        {
            const auto [b, e, flag]{st[--stSize]};

            auto r{e};
            for (auto l{b}; l < r; ++l)
            {
                while ((nums[*l] & flag) && l < --r)
                {
                    swap(*l, *r);
                }
            }

            if (const auto f{flag >> 1}; f)
            {
                if (b + 1 < r)
                    st[stSize++] = {b, r, f};

                if (r + 1 < e)
                    st[stSize++] = {r, e, f};
            }
        }
    }
};
