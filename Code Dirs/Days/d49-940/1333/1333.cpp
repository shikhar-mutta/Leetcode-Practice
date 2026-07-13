// Link: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of restaurants.
    // SC: O(n) for storing the kept restaurants.
    // Approach:
    // 1. Iterate through the restaurants and filter out the ones that do not meet the criteria.
    // 2. Store the kept restaurants in a vector of pairs {rating, id}.
    // 3. Sort the kept restaurants in descending order of rating and id.
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {
        // restaurant = [id, rating, veganFriendly, price, distance]
        vector<pair<int, int>> kept; // {rating, id}
        for (auto &r : restaurants)
        {
            if (veganFriendly && !r[2])
                continue;
            if (r[3] > maxPrice || r[4] > maxDistance)
                continue;
            kept.push_back({r[1], r[0]});
        }
        sort(kept.begin(), kept.end(), greater<pair<int, int>>());
        vector<int> res;
        for (auto &[rating, id] : kept)
            res.push_back(id);
        return res;
    }
};
