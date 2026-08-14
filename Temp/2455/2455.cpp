// Link: https://leetcode.com/problems/average-value-of-even-numbers-that-are-divisible-by-three/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, count = 0;
        for (int x : nums) {
            if (x % 6 == 0) { sum += x; count++; }
        }
        return count == 0 ? 0 : sum / count;
    }
};
