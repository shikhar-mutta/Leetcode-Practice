// Link: https://leetcode.com/problems/find-in-mountain-array/description/

#include <bits/stdc++.h>
using namespace std;

// Hidden API — implementation lives in the driver.
class MountainArray
{
public:
    int get(int index);
    int length();
};

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution
{
public:
    // TC: O(log n)  SC: O(1)
    int findInMountainArray(int target, MountainArray &mountainArr)
    {
        int n = mountainArr.length();

        // 1) Find the peak: 2 get() calls per iteration.
        int l = 0, r = n - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (mountainArr.get(m) < mountainArr.get(m + 1))
                l = m + 1; // still climbing -> peak is to the right
            else
                r = m; // descending (or at peak) -> peak is here or left
        }
        int peak = l;

        // 2) Search ascending half [0, peak]; earliest index wins.
        int idx = binarySearch(mountainArr, target, 0, peak, true);
        if (idx != -1)
            return idx;

        // 3) Search descending half [peak + 1, n - 1].
        return binarySearch(mountainArr, target, peak + 1, n - 1, false);
    }

private:
    // asc == true  -> values increasing, go right when val < target
    // asc == false -> values decreasing, go right when val > target
    int binarySearch(MountainArray &arr, int target, int lo, int hi, bool asc)
    {
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            int val = arr.get(mid);
            if (val == target)
                return mid;
            if ((val < target) == asc)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
};