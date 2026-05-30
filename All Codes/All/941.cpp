// Link: https://leetcode.com/problems/valid-mountain-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
            return false; // A mountain array must have at least 3 elements
        int i = 0, n = arr.size();
        // walk up
        while (i + 1 < n && arr[i] < arr[i + 1])
            i++;
        // peak can't be first or last
        if (i == 0 || i == n - 1)
            return false;
        // walk down
        while (i + 1 < n && arr[i] > arr[i + 1])
            i++;
        return i == n - 1; // if we reached the end, it's a valid mountain array
    }
};
