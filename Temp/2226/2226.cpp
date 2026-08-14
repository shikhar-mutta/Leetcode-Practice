// Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long lo = 1, hi = *max_element(candies.begin(), candies.end());
        int best = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long piles = 0;
            for (int c : candies) piles += c / mid;
            if (piles >= k) {
                best = (int)mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
    }
};
