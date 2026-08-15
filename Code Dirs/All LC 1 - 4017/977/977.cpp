// Link: https://leetcode.com/problems/squares-of-a-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int lo = 0, hi = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int a = nums[lo]*nums[lo], b = nums[hi]*nums[hi];
            if (a > b) { res[i] = a; lo++; }
            else { res[i] = b; hi--; }
        }
        return res;
    }
};
