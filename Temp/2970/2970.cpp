// Link: https://leetcode.com/problems/count-the-number-of-incremovable-subarrays-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStrictlyIncreasing(vector<int>& v) {
        for (int i = 1; i < (int)v.size(); i++)
            if (v[i] <= v[i-1]) return false;
        return true;
    }

    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> rem;
                for (int k = 0; k < i; k++) rem.push_back(nums[k]);
                for (int k = j + 1; k < n; k++) rem.push_back(nums[k]);
                if (isStrictlyIncreasing(rem)) cnt++;
            }
        }
        return cnt;
    }
};
