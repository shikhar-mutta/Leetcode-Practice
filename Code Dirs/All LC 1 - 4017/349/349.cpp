// Link: https://leetcode.com/problems/intersection-of-two-arrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m)  SC: O(n)
// Approach: put nums1 into a set, scan nums2 for matches, dedupe via a
// second set
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> found;
        for (int x : nums2) if (set1.count(x)) found.insert(x);
        vector<int> res(found.begin(), found.end());
        sort(res.begin(), res.end());
        return res;
    }
};
