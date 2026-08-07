// Link: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(1)
// Approach: exponentially expand the search bound until reader.get(bound) exceeds target or hits INT_MAX sentinel, then binary search within that bound.
class Solution {
public:
    int search(ArrayReader& reader, int target) {
        int lo = 0, hi = 1;
        while (reader.get(hi) < target) {
            lo = hi;
            hi *= 2;
        }
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = reader.get(mid);
            if (val == target) return mid;
            if (val > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};
