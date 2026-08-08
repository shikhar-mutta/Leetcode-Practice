// Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(), candies.end());
        vector<bool> res;
        for (int c : candies) res.push_back(c + extraCandies >= mx);
        return res;
    }
};
