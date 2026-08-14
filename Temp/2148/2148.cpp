// Link: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int count = 0;
        for (int x : nums) if (x > mn && x < mx) count++;
        return count;
    }
};
