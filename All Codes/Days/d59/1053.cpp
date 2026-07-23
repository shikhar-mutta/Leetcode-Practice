// Link: https://leetcode.com/problems/previous-permutation-with-one-swap/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> prevPermOpt1(vector<int> &arr)
    {
        int n = arr.size();

        // 1. find rightmost i with arr[i] > arr[i+1]
        int i = n - 2;
        while (i >= 0 && arr[i] <= arr[i + 1])
            i--;
        if (i < 0)
            return arr; // already smallest

        // 2. to the right of i, find the largest value strictly less than
        // arr[i]
        int j = n - 1;
        while (arr[j] >= arr[i])
            j--;

        // 3. if duplicates of that value exist, pick the leftmost one
        while (j > 0 && arr[j] == arr[j - 1])
            j--;

        swap(arr[i], arr[j]);
        return arr;
    }
};