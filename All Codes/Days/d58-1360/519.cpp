// Link: https://leetcode.com/problems/random-flip-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for flip, O(1) for reset
// SC: O(k) where k is the number of flips before reset
// Approach:
//  1. Use a mapping to keep track of the flipped indices and their corresponding values.
//  2. When flipping, generate a random index and check if it has been flipped before. If it has, use the mapped value instead. If not, use the index itself.
//  3. After flipping, update the mapping to point the flipped index to the last unflipped index, and decrement the size of the unflipped indices.
//  4. When resetting, clear the mapping and reset the size to the total number of indices in the matrix.
// 5. Return the flipped index as a pair of row and column.
class Solution
{
public:
    Solution(int m, int n) : m(m), n(n), gen(rd()) { reset(); }

    vector<int> flip()
    {
        std::uniform_int_distribution<int> distrib(0, size - 1);
        int index = distrib(gen);

        int val = index;
        if (mapping.contains(index))
        {
            val = mapping[index];
        }

        int last = size - 1;
        if (mapping.contains(last))
        {
            last = mapping[last];
        }
        mapping[index] = last;

        size--;
        return {val / n, val % n};
    }

    void reset()
    {
        size = m * n;
        mapping.clear();
    }

private:
    int m;
    int n;
    int size;
    unordered_map<int, int> mapping;

    std::random_device rd;
    std::mt19937 gen;
};
