// Link: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (nums[i] + nums[j] == target) ans++;
            }
        }
        return ans;
    }
};
