// Link: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<int,int> cnt;
        for (int x : nums) cnt[x]++;
        for (auto& [val, c] : cnt) {
            if (c == 0) continue;
            int need = c;
            for (int i = 0; i < k; i++) {
                if (cnt[val + i] < need) return false;
                cnt[val + i] -= need;
            }
        }
        return true;
    }
};
