// Link: https://leetcode.com/problems/k-divisible-elements-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> distinct;
        for (int i = 0; i < n; i++) {
            int divCount = 0;
            vector<int> sub;
            for (int j = i; j < n; j++) {
                if (nums[j] % p == 0) divCount++;
                if (divCount > k) break;
                sub.push_back(nums[j]);
                distinct.insert(sub);
            }
        }
        return distinct.size();
    }
};
