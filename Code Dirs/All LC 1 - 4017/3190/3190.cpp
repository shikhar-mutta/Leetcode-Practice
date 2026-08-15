// Link: https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        for (int x : nums) {
            int r = x % 3;
            cnt += min(r, 3 - r);
        }
        return cnt;
    }
};
