// Link: https://leetcode.com/problems/minimum-deletions-to-make-array-beautiful/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        int kept = 0;
        int lastKept = INT_MIN;
        for (int x : nums) {
            if (kept % 2 == 0) {
                lastKept = x;
                kept++;
            } else if (x != lastKept) {
                lastKept = x;
                kept++;
            }
        }
        if (kept % 2 != 0) kept--;
        return n - kept;
    }
};
