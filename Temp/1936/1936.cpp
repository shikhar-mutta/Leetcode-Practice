// Link: https://leetcode.com/problems/add-minimum-number-of-rungs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        long long prev = 0;
        long long count = 0;
        for (int r : rungs) {
            long long gap = r - prev;
            count += (gap - 1) / dist;
            prev = r;
        }
        return (int)count;
    }
};
