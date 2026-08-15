// Link: https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        long long count = 0;
        for (int i = 0; i < n; i++) {
            long long x = 0, y = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) x++; else y++;
                if (y > 0 && x * (long long)b <= (long long)a * y) count++;
            }
        }
        return (int)count;
    }
};
