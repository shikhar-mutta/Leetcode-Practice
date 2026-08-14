// Link: https://leetcode.com/problems/find-if-digit-game-can-be-won/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        long long single = 0, multi = 0;
        for (int x : nums) {
            if (x < 10) single += x;
            else multi += x;
        }
        return single != multi;
    }
};
