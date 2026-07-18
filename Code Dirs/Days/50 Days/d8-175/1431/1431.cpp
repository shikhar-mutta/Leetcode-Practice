// Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        // Find the maximum number of candies any kid has
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for (int c : candies) // for each kid's candies
            ans.push_back(c + extraCandies >= mx);
        return ans;
    }
};
