// Link: https://leetcode.com/problems/maximize-the-total-height-of-unique-towers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        long long total = 0;
        long long prev = LLONG_MAX;
        for (int h : maximumHeight) {
            long long assigned = min((long long)h, prev - 1);
            if (assigned <= 0) return -1;
            total += assigned;
            prev = assigned;
        }
        return total;
    }
};
