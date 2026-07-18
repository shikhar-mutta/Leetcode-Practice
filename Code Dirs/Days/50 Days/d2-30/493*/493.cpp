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
            while (right <= high && (long long)nums[i] > 2LL * nums[right])
                right++;
            cnt += right - (mid + 1);
        }

        int left = low;
        right = mid + 1;
        temp.clear();
        while (left <= mid && right <= high)
            temp.push_back(nums[left] <= nums[right] ? nums[left++] : nums[right++]);
        while (left <= mid)
            temp.push_back(nums[left++]);
        while (right <= high)
            temp.push_back(nums[right++]);
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
        temp.reserve(nums.size());
        return mergeSort(nums, 0, nums.size() - 1);
    }
};
