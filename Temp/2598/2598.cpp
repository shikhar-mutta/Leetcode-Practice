// Link: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> count(value, 0);
        for (int x : nums) {
            int r = ((x % value) + value) % value;
            count[r]++;
        }
        int i = 0;
        while (true) {
            int r = i % value;
            if (count[r] == 0) return i;
            count[r]--;
            i++;
        }
    }
};
