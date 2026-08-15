// Link: https://leetcode.com/problems/minimum-impossible-or/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        long long p = 1;
        while (s.count((int)p)) p *= 2;
        return (int)p;
    }
};
