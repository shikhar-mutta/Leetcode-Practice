// Link: https://leetcode.com/problems/count-almost-equal-pairs-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) where n is the length of the nums array
// SC: O(n) where n is the length of the nums array
// Approach: We can use a hash map to count the frequency of each number in the nums array. Then, we can iterate through the unique numbers in the hash map and for each number, we can check if there are any other numbers that are almost equal to it (i.e., differ by at most 3). We can do this by checking the numbers that are within the range of [num - 3, num + 3]. If we find any such numbers, we can add the product of their frequencies to the result. Finally, we return the result.
class Solution
{
    static const constexpr uint64_t BORROW_BITS = 0x80808080808080;

    static bool canMatch(uint64_t a, uint64_t b, uint64_t matchBits)
    {
        auto diffBits = matchBits ^ BORROW_BITS;
        auto offset = std::countr_zero(diffBits) - 7;
        const auto key = 1 << (int32_t)(a >> offset & 0xF) |
                         1 << (int32_t)(b >> offset & 0xF);
        for (diffBits &= diffBits - 1; diffBits != 0;
             diffBits &= diffBits - 1)
        {
            offset = std::countr_zero(diffBits) - 7;
            const auto curr = 1 << (int32_t)(a >> offset & 0xF) |
                              1 << (int32_t)(b >> offset & 0xF);
            if (key == curr)
                return true;
        }
        return false;
    }

    static std::pair<uint64_t, uint32_t> process(int32_t n)
    {
        uint64_t bcd{};
        int32_t offset{};
        uint32_t counts{};
        for (; n >= 10; offset += 8, n /= 10)
        {
            const auto digit = n % 10;
            bcd |= (uint64_t)(uint32_t)digit << offset;
            counts += 1U << digit * 3;
        }
        counts += 1U << n * 3;
        return {bcd | (uint64_t)(uint32_t)n << offset, counts >> 3};
    }

public:
    int32_t countPairs(std::vector<int32_t> &nums)
    {
        std::unordered_map<int32_t, int32_t> counts;
        for (const auto n : nums)
            ++counts[n];

        std::unordered_map<uint32_t, std::vector<std::pair<uint64_t, int32_t>>>
            groups;
        int32_t res = 0;
        for (const auto [n, count] : counts)
        {
            const auto [bcd, key] = process(n);
            groups[key].emplace_back(bcd, count);
            res += count * count - count >> 1;
        }

        for (const auto [_, group] : groups)
        {
            for (auto l = 0; l < group.size() - 1; ++l)
            {
                const auto [lN, lC] = group[l];
                for (auto r = l + 1; r < group.size(); ++r)
                {
                    const auto [rN, rC] = group[r];
                    const auto diff = lN ^ rN;
                    const auto matchBits = BORROW_BITS - diff & BORROW_BITS;
                    const auto diffCount = 7 ^ std::popcount(matchBits);
                    if (diffCount < 4 ||
                        diffCount == 4 && canMatch(lN, rN, matchBits))
                        res += lC * rC;
                }
            }
        }
        return res;
    }
};
