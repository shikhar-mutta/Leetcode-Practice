// Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
//  Approach: flatten the structure into a single array of pairs (value, list index),
//  sort it, and then use a two-pointer sliding window to find the smallest range
//  that contains at least one element from each of the k lists. The window is expanded
//  by moving the right pointer and contracted by moving the left pointer while maintaining
//  a count of how many unique lists are represented in the current window. The smallest
//  range is updated whenever a valid window is found.
auto FastIO = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution
{
private:
    struct Element
    {
        int val;
        int listIdx;

        // Custom comparator for fast sorting
        bool operator<(const Element &other) const
        {
            return val < other.val;
        }
    };

public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size();

        // Calculate total elements to pre-allocate memory
        int totalElements = 0;
        for (int i = 0; i < k; ++i)
        {
            totalElements += nums[i].size();
        }

        vector<Element> ordered;
        ordered.reserve(totalElements); // Prevents dynamic reallocation overhead

        // Flatten the structure
        for (int i = 0; i < k; ++i)
        {
            for (int num : nums[i])
            {
                ordered.push_back({num, i});
            }
        }

        // Highly optimized sort using our compact struct
        sort(ordered.begin(), ordered.end());

        vector<int> counts(k, 0);
        int uniqueListsInWindow = 0;
        int left = 0;

        int start = 0;
        int end = INT_MAX;

        // Two-pointer sliding window execution
        for (int right = 0; right < totalElements; ++right)
        {
            int rightList = ordered[right].listIdx;

            if (counts[rightList] == 0)
            {
                uniqueListsInWindow++;
            }
            counts[rightList]++;

            // Contract the window as long as it contains elements from all k lists
            while (uniqueListsInWindow == k)
            {
                int currentMin = ordered[left].val;
                int currentMax = ordered[right].val;

                // Track the narrowest span
                if ((long long)currentMax - currentMin < (long long)end - start)
                {
                    start = currentMin;
                    end = currentMax;
                }

                int leftList = ordered[left].listIdx;
                counts[leftList]--;
                if (counts[leftList] == 0)
                {
                    uniqueListsInWindow--;
                }
                left++;
            }
        }

        return {start, end};
    }
};