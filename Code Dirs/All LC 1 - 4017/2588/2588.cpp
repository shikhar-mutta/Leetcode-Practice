// Link: https://leetcode.com/problems/count-the-number-of-beautiful-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        unordered_map<int,int> freq;
        freq[0] = 1;
        int prefix = 0;
        long long count = 0;
        for (int x : nums) {
            prefix ^= x;
            count += freq[prefix];
            freq[prefix]++;
        }
        return count;
    }
};
