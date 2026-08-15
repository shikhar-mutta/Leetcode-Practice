// Link: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int neededDays = 1, cur = 0;
            for (int w : weights) {
                if (cur + w > mid) { neededDays++; cur = 0; }
                cur += w;
            }
            if (neededDays <= days) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
