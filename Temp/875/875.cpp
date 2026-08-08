// Link: https://leetcode.com/problems/koko-eating-bananas/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long hours = 0;
            for (int p : piles) hours += (p + mid - 1) / mid;
            if (hours <= h) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
