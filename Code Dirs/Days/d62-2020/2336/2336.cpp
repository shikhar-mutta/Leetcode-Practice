// Link: https://leetcode.com/problems/smallest-number-in-infinite-set/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per popSmallest/addBack for typical use (bounded by
//     bucket size 240; degrades if buckets aren't advanced correctly, see
//     note below), O(log(active buckets)) for addBack's partition_point
// SC: O(distinct 240-value buckets touched)
// Approach: numbers are grouped into fixed-size 240-value buckets, each a
// bitset tracking which values in that range are still "in" the set.
// popSmallest scans the lowest active bucket (mRanges.back(), since
// mRanges is kept sorted with the smallest range at the back) for its
// lowest set bit. addBack finds or creates the bucket covering a given
// value (via partition_point on begin, descending) and sets that bit.
class SmallestInfiniteSet {
    constexpr static std::size_t kLowBucketSize = 240U;
    struct alignas(32) LowBucket {
        std::uint16_t begin;
        std::bitset<kLowBucketSize> values;

        static std::uint16_t valueToRange(int v) {
            return v - (v % kLowBucketSize);
        };
        std::uint16_t nextRange() const { return begin + kLowBucketSize; }
        std::size_t toBit(int v) const { return v - begin; }
        void addValue(int v) { values.set(toBit(v), true); }
        void removeValue(int v) { values.set(toBit(v), false); }
        int popSmallest() {
            int v = 0;
            while (!values.test(v)) {
                ++v;
            }
            values.set(v, false);
            return begin + v;
        }
        void setAll(bool v = true) {
            values.reset();
            if (v) {
                values.flip();
            }
        }

        bool inRange(int v) const { return valueToRange(v) == begin; }

        bool isEmpty() { return values.none(); }
    };
    std::vector<LowBucket> mRanges;

public:
    SmallestInfiniteSet() {
        mRanges.push_back(LowBucket{0});
        mRanges.back().setAll(true);
        mRanges.back().popSmallest();
    }
    int popSmallest() {
        int res = mRanges.back().popSmallest();
        if (mRanges.back().isEmpty()) {
            auto const nextRange = mRanges.back().nextRange();
            mRanges.pop_back();
            if (mRanges.empty() || !mRanges.back().begin == nextRange) {
                mRanges.push_back(LowBucket{nextRange});
                mRanges.back().setAll(true);
            }
        }
        return res;
    }

    void addBack(int num) {
        auto found = std::partition_point(
            mRanges.begin(), mRanges.end(),
            [target = LowBucket::valueToRange(num)](auto const v) {
                return v.begin > target;
            });
        if (found == mRanges.begin() && !found->inRange(num)) {
            return;
        }
        if ((found == mRanges.end()) || !found->inRange(num)) {
            auto n =
                mRanges.insert(found, LowBucket{LowBucket::valueToRange(num)});
            n->addValue(num);
            return;
        } else {
            found->addValue(num);
        }
    }
};
