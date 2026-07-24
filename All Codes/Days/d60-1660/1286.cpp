// Link: https://leetcode.com/problems/iterator-for-combination/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n) where n is the size of the string
//  Approach:
//   1. We can use a vector of indices to represent the current combination. The indices vector will have a size equal to the combination length and will be initialized with the first combination (i.e., [0, 1, 2, ..., combination_length - 1]). We can then generate the next combination by finding the rightmost index that can be incremented and updating the indices vector accordingly. If no such index exists, we have generated all combinations and can set a flag to indicate that there are no more combinations left. The next() function will return the current combination as a string and advance the indices vector to the next combination. The hasNext() function will return whether there are more combinations left to generate.
class CombinationIterator
{
    std::string characters_;
    std::vector<int> indices_;
    bool has_next_ = true;

    void advance()
    {
        const int n = static_cast<int>(characters_.size());
        const int k = static_cast<int>(indices_.size());

        int pivot = k - 1;

        while (pivot >= 0 && indices_[pivot] == n - k + pivot)
        {
            --pivot;
        }

        if (pivot < 0)
        {
            has_next_ = false;
            return;
        }

        ++indices_[pivot];

        for (int i = pivot + 1; i < k; ++i)
        {
            indices_[i] = indices_[i - 1] + 1;
        }
    }

public:
    CombinationIterator(string characters, int combination_length)
        : characters_(std::move(characters)), indices_(combination_length)
    {
        std::iota(indices_.begin(), indices_.end(), 0);
    }

    std::string next()
    {
        assert(has_next_);

        std::string result;
        result.reserve(indices_.size());

        for (const int index : indices_)
        {
            result.push_back(characters_[index]);
        }

        advance();
        return result;
    }

    bool hasNext() const noexcept { return has_next_; }
};
