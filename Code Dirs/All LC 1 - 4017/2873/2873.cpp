// Link: https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, maxI = 0, maxDiff = 0;
        for (int x : nums) {
            ans = max(ans, maxDiff * x);
            maxDiff = max(maxDiff, maxI - x);
            maxI = max(maxI, (long long)x);
        }
        return ans;
    }
};
