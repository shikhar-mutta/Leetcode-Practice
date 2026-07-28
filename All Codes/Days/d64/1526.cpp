// Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans = target[0];
        for (int i = 1; i < (int)target.size(); i++)
            if (target[i] > target[i-1]) ans += target[i] - target[i-1];
        return ans;
    }
};
