// Link: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int,int> cnt;
        for (int a : nums)
            for (int b : nums)
                cnt[a & b]++;

        int res = 0;
        for (int c : nums)
            for (auto& [mask, freq] : cnt)
                if ((mask & c) == 0) res += freq;
        return res;
    }
};
