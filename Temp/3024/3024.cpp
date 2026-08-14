// Link: https://leetcode.com/problems/type-of-triangle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string triangleType(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        if (v[0] + v[1] <= v[2]) return "none";
        if (v[0] == v[1] && v[1] == v[2]) return "equilateral";
        if (v[0] == v[1] || v[1] == v[2]) return "isosceles";
        return "scalene";
    }
};
