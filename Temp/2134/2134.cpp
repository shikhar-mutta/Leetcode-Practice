// Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int k = count(nums.begin(), nums.end(), 1);
        if (k == 0 || k == n) return 0;
        int curOnes = 0;
        for (int i = 0; i < k; i++) curOnes += nums[i];
        int maxOnes = curOnes;
        for (int i = 1; i < n; i++) {
            int add = nums[(i + k - 1) % n];
            int remove = nums[(i - 1) % n];
            curOnes += add - remove;
            maxOnes = max(maxOnes, curOnes);
        }
        return k - maxOnes;
    }
};
