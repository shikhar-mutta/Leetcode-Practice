// Link: https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn + k*n) SC: O(n)
    vector<int> getFinalState(vector<int> &nums, int k, int multiplier)
    {
        int n = nums.size();

        vector<pair<int, int>> temp(n, {0, 0});
        for (int i = 0; i < n; i++)
            temp[i] = {nums[i], i};

        sort(temp.begin(), temp.end()); // Sort Array
        for (int i = 0; i < k; i++)     // k iterations
        {
            temp[0].first *= multiplier;
            int j = 0;
            while (j + 1 < n && temp[j] > temp[j + 1]) // Pair comparison and swap
            {
                swap(temp[j], temp[j + 1]);
                j++;
            }
        }
        for (int i = 0; i < n; i++)
            nums[temp[i].second] = temp[i].first;
        return nums;
    }
};
