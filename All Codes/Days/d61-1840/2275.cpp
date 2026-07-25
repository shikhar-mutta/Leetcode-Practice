// Link: https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 32), n = candidates.size()
// SC: O(1) (fixed 32-slot bit-count array)
// Approach: a subset's bitwise AND is nonzero iff some bit position is set
// in every chosen element, so the largest such subset is just the largest
// group of numbers all sharing a common set bit. Count, per bit position,
// how many candidates have that bit set; the answer is the max count over
// all 32 bit positions.
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        const size_t INT_SIZE = sizeof(int) * 8;
        std::array<int, INT_SIZE> count_of_bits = {0};
        for (int candidate : candidates) {
            for (size_t i = 0; i < INT_SIZE; ++i) {
                count_of_bits[i] += (candidate & (1ul << i)) != 0;
            }
        }
        int largestCombination = 0;
        for (int possibleLargestCombination : count_of_bits) {
            largestCombination =
                max(largestCombination, possibleLargestCombination);
        }
        return largestCombination;
    }
};
