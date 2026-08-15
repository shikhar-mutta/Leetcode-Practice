// Link: https://leetcode.com/problems/longest-common-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

#include <algorithm>
#include <cstdint>
#include <string_view>
#include <vector>

namespace ParallelMemory
{
    std::vector<uint64_t> d_blocks;
    std::vector<std::vector<uint64_t>> match_masks;
} // namespace ParallelMemory

// TC: O(m * n / 64) where m and n are the lengths of the two strings
// SC: O(n / 64) for the bitmask arrays
//   Approach:
//    1. Use a bit-parallel dynamic programming approach to calculate the longest common subsequence (LCS) of two strings.
//    2. Represent the DP table as a bitmask, where each bit corresponds to a character in the second string.
//    3. For each character in the first string, update the bitmask based on matches with characters in the second string and the previous state of the DP table.
//    4. Use bitwise operations to efficiently compute the LCS length, taking advantage of the fact that we can process 64 characters at a time using 64-bit integers.
//    5. Count the number of set bits in the final bitmask to determine the length of the longest common subsequence.
//    6. Return the length of the longest common subsequence.
class Solution
{
public:
    int longestCommonSubsequence(std::string_view text1,
                                 std::string_view text2) noexcept
    {
        if (text1.size() < text2.size())
        {
            std::swap(text1, text2);
        }

        const size_t m = text1.size();
        const size_t n = text2.size();
        if (n == 0)
            return 0;

        const size_t num_blocks = (n + 63) / 64;

        ParallelMemory::d_blocks.assign(num_blocks, 0ULL);
        uint64_t *__restrict__ D = ParallelMemory::d_blocks.data();

        ParallelMemory::match_masks.assign(
            256, std::vector<uint64_t>(num_blocks, 0ULL));

        for (size_t j = 0; j < n; ++j)
        {
            size_t block_idx = j / 64;
            size_t bit_idx = j % 64;
            uint8_t character = static_cast<uint8_t>(text2[j]);
            ParallelMemory::match_masks[character][block_idx] |=
                (1ULL << bit_idx);
        }

        // Main Loop: Stream through text1 character by character
        for (size_t i = 0; i < m; ++i)
        {
            uint8_t c1 = static_cast<uint8_t>(text1[i]);
            const uint64_t *__restrict__ X =
                ParallelMemory::match_masks[c1].data();

            // Track the bit shifting carry over between blocks
            uint64_t shift_carry =
                1ULL; // The base formula starts with '| 1' at column 0

            // Track the mathematical borrow bit for subtraction between blocks
            uint64_t borrow = 0ULL;

            // Process the entire row 64 columns at a time
            for (size_t b = 0; b < num_blocks; ++b)
            {
                uint64_t current_D = D[b];
                uint64_t current_X = X[b];

                uint64_t Y = current_D | current_X;

                // 1. Calculate shifted D for this block and inject the carry
                // from the last block
                uint64_t shifted_D = (current_D << 1) | shift_carry;
                shift_carry = (current_D >>
                               63); // Save the bit that fell off the left side

                // 2. Perform long subtraction across blocks using a manual
                // borrow check
                uint64_t Z = Y - shifted_D - borrow;

                // Determine if this block allocation needed to borrow from the
                // next block. Underflow occurs if Y is smaller than what we
                // subtracted from it.
                if (Z > Y || (Z == Y && (shifted_D + borrow) > 0))
                {
                    borrow = 1ULL;
                }
                else
                {
                    borrow = 0ULL;
                }

                // 3. Finalize the DP state update for this 64-column chunk
                D[b] = Y & (Z ^ Y);
            }
        }

        // Count all the active set bits across all blocks to find the total LCS
        // length
        int total_lcs = 0;
        for (size_t b = 0; b < num_blocks; ++b)
        {
            total_lcs += __builtin_popcountll(D[b]);
        }

        return total_lcs;
    }
};