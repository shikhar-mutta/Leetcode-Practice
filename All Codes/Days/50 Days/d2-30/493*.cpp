// Link: https://leetcode.com/problems/reverse-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> temp;

    int countAndMerge(vector<int> &nums, int low, int mid, int high)
    {
        int cnt = 0;
        int right = mid + 1;

        // Count reverse pairs
        for (int i = low; i <= mid; i++)
        {
            // Move the right pointer until we find an element that is not a reverse pair with nums[i].
            while (right <= high && (long long)nums[i] > 2LL * nums[right])
                right++;
            // All elements from mid+1 to right-1 are reverse pairs with nums[i].
            cnt += right - (mid + 1);
        }

        int left = low;
        right = mid + 1;
        temp.clear();
        // Merge the two halves while counting reverse pairs.
        while (left <= mid && right <= high)
            temp.push_back(nums[left] <= nums[right] ? nums[left++] : nums[right++]);
        while (left <= mid)
            temp.push_back(nums[left++]);
        while (right <= high)
            temp.push_back(nums[right++]);
        // Copy the merged elements back to the original array.
        copy(temp.begin(), temp.end(), nums.begin() + low);

        return cnt;
    }

    int mergeSort(vector<int> &nums, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = (low + high) / 2;
        // Count reverse pairs in left half, right half and across halves
        return mergeSort(nums, low, mid) +
               mergeSort(nums, mid + 1, high) +
               countAndMerge(nums, low, mid, high);
    }

public:
    int reversePairs(vector<int> &nums)
    {
        // Reserve space for the temporary vector to avoid multiple allocations during merging.
        temp.reserve(nums.size());
        // Start the merge sort and counting process.
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
