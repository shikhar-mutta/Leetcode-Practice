// Link: https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) due to sorting the pairs and indices.
    // SC: O(n) for storing pairs and indices.
    // Approach:
    //  1. Create a vector of pairs where each pair contains the value and its original index.
    //  2. Sort the pairs based on the values to get the order of elements.
    //  3. Create an index array to keep track of the original indices of the sorted elements.
    //  4. Iterate through the sorted pairs and check if the difference between consecutive elements exceeds the limit.
    //  5. If it does, sort the indices of the elements in that segment to ensure they are in the correct order.
    //  6. Finally, construct the result array using the sorted indices and return it.
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit)
    {
        int len = nums.size();
        vector<int> result = nums, inds(len);
        vector<pair<int, int>> pairs(len);
        for (int i = 0; i < len; ++i)
        {
            pairs[i] = {nums[i], i};
        }
        sort(pairs.begin(), pairs.end());
        for (int i = 0; i < len; ++i)
        {
            inds[i] = pairs[i].second;
        }
        int last = 0;
        for (int i = 1; i < len; ++i)
        {
            if (pairs[i].first - pairs[i - 1].first > limit)
            {
                sort(inds.begin() + last, inds.begin() + i);
                last = i;
            }
        }
        sort(inds.begin() + last, inds.end());
        for (int i = 0; i < len; ++i)
        {
            result[inds[i]] = pairs[i].first;
        }
        return result;
    }
};