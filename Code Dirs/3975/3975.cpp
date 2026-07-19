// Link: https://leetcode.com/problems/filter-occupied-intervals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) where n is the number of occupied intervals. The sorting step dominates the time complexity.
// SC: O(n) for storing the filtered intervals and the temporary data structures used during sorting
// Approach:
// 1. We first filter the occupied intervals to only include those that overlap with the free interval [freeStart, freeEnd].
// 2. We then sort the filtered intervals based on their start times using a custom sorting function
// 3. Finally, we merge the overlapping intervals and return the result.

#pragma GCC optimize("fast-math", "no-stack-protector")

#define INL __attribute__((always_inline))
#define HOT __attribute__((hot))
#define AVX2 __attribute__((target("avx2")))
#define INL_ATTR noexcept INL HOT
#define OUTL_ATTR noexcept HOT
#define LAM_ATTR noexcept INL HOT

#pragma GCC diagnostic ignored "-Wshift-op-parentheses"
#pragma GCC diagnostic ignored "-Wvla-cxx-extension"
#pragma GCC diagnostic ignored "-Wunqualified-std-cast-call"

#include <immintrin.h>

template <uint8_t RBITS>
HOT AVX2 void partial_sum_v256(uint32_t *const data) noexcept
{
    constexpr uint8_t V = 256 / (sizeof(uint32_t) * 8);
    constexpr uint n = 1u << RBITS;
    auto current = _mm256_set1_epi32(0);
#pragma unroll 8
    for (uint i = 0; i < n; i += V)
    {
        auto d = _mm256_load_si256((const __m256i *)&data[i]);
        d = _mm256_add_epi32(d, _mm256_slli_si256(d, 1 * sizeof(uint32_t)));
        d = _mm256_add_epi32(d, _mm256_slli_si256(d, 2 * sizeof(uint32_t)));
        const auto c = _mm256_set_m128i(
            _mm_set1_epi32(_mm256_extract_epi32(d, V / 2 - 1)),
            _mm_setzero_si128());
        d = _mm256_add_epi32(d, c);
        d = _mm256_add_epi32(d, current);
        _mm256_store_si256((__m256i *)&data[i], d);
        current = _mm256_set1_epi32(_mm256_extract_epi32(d, V - 1));
    }
}

template <class It, class Fun, uint8_t RBITS>
HOT auto radix_stable_sort(const It beg, const It end, const uint8_t pos, const It out, const Fun getval) noexcept
{
    constexpr uint RADIX = 1u << RBITS, RMASK = RADIX - 1u;
    alignas(__m256i) uint freqs[RADIX + sizeof(__m256i)] = {};
    for (auto curr = beg; curr < end; curr++)
        freqs[((getval(*curr) >> pos) & RMASK) + 1u]++;
    partial_sum_v256<RBITS>(freqs);
    auto maxv = getval(*beg);
    for (auto curr = beg; curr < end; curr++)
    {
        const auto i = *curr;
        const auto v = getval(i);
        out[freqs[((v >> pos) & RMASK)]++] = i;
        maxv |= v;
    }
    return maxv;
}

template <class It, class Fun, uint8_t SBITS, uint8_t RBITS = SBITS>
HOT void adaptive_sort(const It beg, const It end, const Fun getval, const It temp) noexcept
{
    using T = remove_reference<decltype(*declval<It>())>::type;
    using V = result_of<decltype(getval)(const T)>::type;
    constexpr uint8_t BITSIZE = sizeof(V) * 8u;
    const uint n = end - beg;
    if (n > 1u << (SBITS - 2u))
    {
        const bool large = n > 1u << (RBITS - 2u);
        It bin = beg, ein = end, bout = temp, eout = temp + n;
        T maxi = *beg;
        V maxv = V(-1);
        const auto sortfn = large ? radix_stable_sort<It, Fun, RBITS> : radix_stable_sort<It, Fun, SBITS>;
        const uint8_t bits = large ? RBITS : SBITS;
        for (uint8_t pos = 0; pos < BITSIZE && maxv >> pos; pos += bits)
        {
            maxv = sortfn(bin, ein, pos, bout, getval);
            swap(bin, bout);
            swap(ein, eout);
        }
        if (bout == beg)
            copy(bin, ein, beg);
    }
    else if (n > 2)
    {
        sort(beg, end, [getval](const T i, const T j) LAM_ATTR
             { return getval(i) < getval(j); });
    }
    else if (n == 2 && getval(beg[0]) > getval(beg[1]))
    {
        swap(beg[0], beg[1]);
    }
}

template <class It, class Fun, uint8_t SBITS, uint8_t RBITS = SBITS>
HOT INL void adaptive_sort(const It beg, const It end, const Fun getval) noexcept
{
    using T = remove_reference<decltype(*declval<It>())>::type;
    const uint n = end - beg;
    T temp[n];
    adaptive_sort<It, Fun, SBITS, RBITS>(beg, end, getval, temp);
}

class Solution
{
public:
    static vector<vector<int>> filterOccupiedIntervals(vector<vector<int>> &occupiedIntervals, const uint freeStart, const uint freeEnd)
    {
        constexpr uint16_t N = 50'000;
        constexpr uint8_t SH = 30;
        static uint64_t data[N + 1], temp[N + 1];

        const auto odata = occupiedIntervals.data();
        const uint n = occupiedIntervals.size();
        uint j = 0;
        for (uint i = 0; i < n; i++)
        {
            auto &t = odata[i];
            const uint s = t[0], e = t[1],
                       f = e >= freeStart & s <= freeEnd,
                       g = s<freeStart, h = e> freeEnd,
                       u = f & g ? freeStart - 1 : e,
                       v = f & h ? freeEnd + 1 : s;
            data[j] = (uint64_t(s) << SH) + u;
            j += !f | g;
            data[j] = (uint64_t(v) << SH) + e;
            j += f & h;
        }
        adaptive_sort<uint64_t *, identity, 8, 15>(data, data + j, identity(), temp);
        auto &res = occupiedIntervals;
        uint k = 0, l = *data >> SH, r = *data & (1u << SH) - 1;
        for (uint i = 1; i < j; i++)
        {
            const uint64_t d = data[i];
            const uint s = d >> SH, e = d & (1u << SH) - 1;
            auto &t = res[k];
            if (s > r + 1)
            {
                t[0] = l;
                t[1] = r;
                k++;
                l = s;
                r = e;
            }
            else
            {
                r = max(r, e);
            }
        }
        if (k == res.size())
        {
            res.push_back({(int)l, (int)r});
        }
        else
        {
            if (l > freeEnd | r < freeStart)
            {
                auto &t = res[k];
                t[0] = l;
                t[1] = r;
                k++;
            }
            res.resize(k);
        }
        return move(res);
    }
};

static const auto init = []() noexcept
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();