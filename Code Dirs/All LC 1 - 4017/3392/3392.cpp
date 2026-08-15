// Link: https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i + 2 < (int)nums.size(); i++) {
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) cnt++;
        }
        return cnt;
    }
};
