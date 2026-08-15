// Link: https://leetcode.com/problems/maximum-number-of-pairs-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        int pairs = 0, leftover = 0;
        for (auto& [k, c] : cnt) {
            pairs += c / 2;
            leftover += c % 2;
        }
        return {pairs, leftover};
    }
};
