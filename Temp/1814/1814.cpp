// Link: https://leetcode.com/problems/count-nice-pairs-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rev(int x) {
        int r = 0;
        while (x > 0) { r = r * 10 + x % 10; x /= 10; }
        return r;
    }

    int countNicePairs(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, int> freq;
        long long count = 0;
        for (int x : nums) {
            int diff = x - rev(x);
            count = (count + freq[diff]) % MOD;
            freq[diff]++;
        }
        return (int)count;
    }
};
