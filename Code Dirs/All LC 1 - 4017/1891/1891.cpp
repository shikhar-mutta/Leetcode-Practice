// Link: https://leetcode.com/problems/cutting-ribbons/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<int>& ribbons, int k) {
        int lo = 1, hi = *max_element(ribbons.begin(), ribbons.end());
        int best = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            long long count = 0;
            for (int r : ribbons) count += r / mid;
            if (count >= k) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return best;
    }
};
