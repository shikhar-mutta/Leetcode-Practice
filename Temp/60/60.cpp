// Link: https://leetcode.com/problems/permutation-sequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: factorial number system — k-- for 0-index, at each position pick candidates[k/(n-1)!] then k%=(n-1)!
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> fact(n + 1, 1);
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i;
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);
        k--;
        string res;
        for (int i = n; i >= 1; i--) {
            int idx = k / fact[i-1];
            k %= fact[i-1];
            res += to_string(nums[idx]);
            nums.erase(nums.begin() + idx);
        }
        return res;
    }
};
