// Link: https://leetcode.com/problems/sum-of-unique-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) freq[x]++;
        int sum = 0;
        for (auto& [k, v] : freq) if (v == 1) sum += k;
        return sum;
    }
};
