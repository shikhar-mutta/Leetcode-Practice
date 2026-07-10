// Link: https://leetcode.com/problems/sort-an-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)
// SC: O(n)
// Approach: Merge Sort
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        buf.resize(nums.size());
        mergeSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

private:
    vector<int> buf;

    void mergeSort(vector<int> &a, int lo, int hi)
    {
        if (lo >= hi)
            return;
        int mid = lo + (hi - lo) / 2;
        mergeSort(a, lo, mid);
        mergeSort(a, mid + 1, hi);
        if (a[mid] <= a[mid + 1])
            return; // already in order
        int i = lo, j = mid + 1, k = lo;
        while (i <= mid && j <= hi)
            buf[k++] = a[i] <= a[j] ? a[i++] : a[j++];
        while (i <= mid)
            buf[k++] = a[i++];
        while (j <= hi)
            buf[k++] = a[j++];
        copy(buf.begin() + lo, buf.begin() + hi + 1, a.begin() + lo);
    }
};
