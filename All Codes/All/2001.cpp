// Link: https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the number of rectangles
// SC: O(n) where n is the number of rectangles
//  Approach:
//  1. We will create a vector to store the ratio of length and width for each rectangle
//  2. We will sort the vector and then iterate through it to find the number of pairs of rectangles with the same ratio
//  3. We will use a two pointer approach to find the number of pairs of rectangles with the same ratio
//  4. Finally, we will return the total number of pairs of rectangles with the same ratio.
class Solution
{
public:
    long long interchangeableRectangles(vector<vector<int>> &rectangles)
    {
        vector<double> ans;
        for (const auto &num : rectangles)
        {
            double division = static_cast<double>(num[0]) / num[1];
            ans.push_back(division);
        }
        sort(ans.begin(), ans.end());

        long long ans1 = 0;
        int n = ans.size();
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j < n && ans[j] == ans[i])
            {
                j++;
            }
            long long k = j - i;
            if (k > 1)
            {
                ans1 += (k * (k - 1)) / 2;
            }
            i = j;
        }

        return ans1;
    }
};