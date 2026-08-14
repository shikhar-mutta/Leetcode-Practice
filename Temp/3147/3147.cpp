// Link: https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = energy[i] + (i + k < n ? dp[i+k] : 0);
        }
        return *max_element(dp.begin(), dp.end());
    }
};
