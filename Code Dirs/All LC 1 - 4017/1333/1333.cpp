// Link: https://leetcode.com/problems/filter-restaurants-by-vegan-friendly-price-and-distance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> filtered;
        for (auto& r : restaurants) {
            if (veganFriendly == 1 && r[2] == 0) continue;
            if (r[3] > maxPrice) continue;
            if (r[4] > maxDistance) continue;
            filtered.push_back(r);
        }
        sort(filtered.begin(), filtered.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] != b[1]) return a[1] > b[1];
            return a[0] > b[0];
        });
        vector<int> res;
        for (auto& r : filtered) res.push_back(r[0]);
        return res;
    }
};
