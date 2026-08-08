// Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int x : nums) {
            int digits = to_string(x).size();
            if (digits % 2 == 0) count++;
        }
        return count;
    }
};
