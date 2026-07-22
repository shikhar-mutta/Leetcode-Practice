// Link: https://leetcode.com/problems/4sum-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the length of the input arrays nums1, nums2, nums3, and nums4.
    // SC: O(n^2) since we are using a hash map to store the sums of pairs from nums1 and nums2.
    // Approach:
    //  1. We can use a hash map to store the sums of pairs from nums1 and nums2, along with their counts.
    //  2. Then, we can iterate through all pairs from nums3 and nums4, and for each pair, we can check if the negation of their sum exists in the hash map.
    //  3. If it does, we can add the count of that sum to the total count of quadruplets.
    //  4. Finally, we return the total count of quadruplets that sum to zero.
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> sumCount;
        for (int a : nums1)
            for (int b : nums2)
                sumCount[a + b]++;

        int total = 0;
        for (int c : nums3)
            for (int d : nums4)
            {
                auto it = sumCount.find(-(c + d));
                if (it != sumCount.end())
                    total += it->second;
            }
        return total;
    }
};
