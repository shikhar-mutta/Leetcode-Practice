// Link: https://leetcode.com/problems/find-unique-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        for (int i = 0; i < (int)nums.size(); i++) {
            res += (nums[i][i] == '0') ? '1' : '0';
        }
        return res;
    }
};
