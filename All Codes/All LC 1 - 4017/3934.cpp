// Link: https://leetcode.com/problems/smallest-unique-subarray/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n)  SC: O(n)
// Approach: We can use binary search to find the smallest length of the subarray.
//  We can use a hash function to find the hash of the subarray. We can use a set to store the hashes of the subarrays. We can check if any hash appears exactly once in the set. If it does, we can return true. If it doesn't, we can return false. We can use binary search to find the smallest length of the subarray.
class Solution
{
public:
    bool possible(vector<int> &nums, int len)
    {
        int n = nums.size();

        // Simple Rabin-Karp parameters
        // Using a prime base. Modulo is automatically 2^64 via unsigned overflow.
        unsigned long long base = 100003;
        unsigned long long current_hash = 0;
        unsigned long long power = 1;

        // Precompute base^(len - 1) for discarding the leftmost element
        for (int i = 0; i < len - 1; ++i)
        {
            power = power * base;
        }

        // Vector to store hashes of all subarrays of length 'len'
        vector<unsigned long long> hashes;
        hashes.reserve(n - len + 1); // Optimization to avoid re-allocations

        // 1. Compute the hash of the very first window
        for (int i = 0; i < len; ++i)
        {
            current_hash = current_hash * base + nums[i];
        }
        hashes.push_back(current_hash);

        // 2. Slide the window across the rest of the array
        for (int i = len; i < n; ++i)
        {
            // Remove the oldest element (at index i - len)
            current_hash = current_hash - nums[i - len] * power;

            // Add the newest element (at index i)
            current_hash = current_hash * base + nums[i];

            hashes.push_back(current_hash);
        }

        // 3. Sort the hashes to easily identify unique values in O(N log N)
        sort(hashes.begin(), hashes.end());

        // Check if any hash appears exactly once
        int num_hashes = hashes.size();
        for (int i = 0; i < num_hashes; ++i)
        {
            bool left_diff = (i == 0 || hashes[i] != hashes[i - 1]);
            bool right_diff = (i == num_hashes - 1 || hashes[i] != hashes[i + 1]);

            if (left_diff && right_diff)
            {
                return true; // Found a unique subarray hash!
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int> &nums)
    {
        int l = 1;
        int r = nums.size();
        int ans = -1;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (possible(nums, mid))
            {
                ans = mid;
                r = mid - 1; // Look for a smaller length
            }
            else
            {
                l = mid + 1; // Increase length requirement
            }
        }
        return ans;
    }
};
