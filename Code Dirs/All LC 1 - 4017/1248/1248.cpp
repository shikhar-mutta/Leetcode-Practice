// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        cnt[0] = 1;
        int odd = 0, res = 0;
        for (int x : nums) {
            if (x % 2 != 0) odd++;
            res += cnt[odd - k];
            cnt[odd]++;
        }
        return res;
    }
};
