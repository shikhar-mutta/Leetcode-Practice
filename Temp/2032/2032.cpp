// Link: https://leetcode.com/problems/two-out-of-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int> mask;
        for (int x : nums1) mask[x] |= 1;
        for (int x : nums2) mask[x] |= 2;
        for (int x : nums3) mask[x] |= 4;
        vector<int> res;
        for (auto& [x, m] : mask) {
            if (__builtin_popcount(m) >= 2) res.push_back(x);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
