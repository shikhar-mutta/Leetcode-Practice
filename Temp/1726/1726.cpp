// Link: https://leetcode.com/problems/tuple-with-same-product/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                freq[nums[i] * nums[j]]++;
        long long total = 0;
        for (auto& [k, v] : freq) total += (long long)v * (v - 1) / 2;
        return (int)(total * 8);
    }
};
