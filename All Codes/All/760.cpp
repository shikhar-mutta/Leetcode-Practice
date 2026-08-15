// Link: https://leetcode.com/problems/find-anagram-mappings/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: map each value in nums2 to its index; for each element of nums1, look up that mapping.
class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> idx;
        for (int i = 0; i < (int)nums2.size(); i++) idx[nums2[i]] = i;
        vector<int> res;
        for (int x : nums1) res.push_back(idx[x]);
        return res;
    }
};
