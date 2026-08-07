// Link: https://leetcode.com/problems/majority-element/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: Boyer-Moore voting — candidate survives when count hits 0, guaranteed correct since majority > n/2
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int x : nums) {
            if (count == 0) candidate = x;
            count += (x == candidate) ? 1 : -1;
        }
        return candidate;
    }
};
