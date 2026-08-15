// Link: https://leetcode.com/problems/largest-unique-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        int best = -1;
        for (auto& [val, c] : cnt) if (c == 1) best = max(best, val);
        return best;
    }
};
