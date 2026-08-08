// Link: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == 1) {
                if (last != -1 && i - last - 1 < k) return false;
                last = i;
            }
        }
        return true;
    }
};
