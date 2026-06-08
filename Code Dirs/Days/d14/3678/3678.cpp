// Link: https://leetcode.com/problems/smallest-absent-positive-greater-than-average/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(logn) + O(n) ~ O(nlogn). SC: O(1) (if we ignore the space used by sorting)
    int smallestAbsent(vector<int> &nums)
    {
        int avg = accumulate(nums.begin(), nums.end(), 0LL) / (int)nums.size();
        if (avg < 0)
            avg = 0;
        sort(nums.begin(), nums.end());
        for (int i = avg + 1;; i++)
            if (binary_search(nums.begin(), nums.end(), i))
                continue;
            else
                return i;
    }
};