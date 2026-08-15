// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m)  SC: O(n)
// Approach: frequency map of nums1, scan nums2 decrementing counts, include
// element while count remains positive
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        for (int x : nums1) freq[x]++;
        vector<int> res;
        for (int x : nums2) {
            if (freq[x] > 0) {
                res.push_back(x);
                freq[x]--;
            }
        }
        return res;
    }
};
