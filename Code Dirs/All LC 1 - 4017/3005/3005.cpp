// Link: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxF = 0;
        for (int x : nums) maxF = max(maxF, ++freq[x]);
        int cnt = 0;
        for (auto& [k, v] : freq) if (v == maxF) cnt += v;
        return cnt;
    }
};
