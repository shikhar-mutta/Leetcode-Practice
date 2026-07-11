// Link: https://leetcode.com/problems/pancake-sorting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> flips;
        for (int k = n; k > 1; k--)
        {
            int idx = find(arr.begin(), arr.begin() + k, k) - arr.begin();
            if (idx == k - 1)
                continue;
            if (idx > 0)
            {
                flips.push_back(idx + 1);
                reverse(arr.begin(), arr.begin() + idx + 1);
            }
            flips.push_back(k);
            reverse(arr.begin(), arr.begin() + k);
        }
        return flips;
    }
};
