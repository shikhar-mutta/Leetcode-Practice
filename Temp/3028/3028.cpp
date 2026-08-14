// Link: https://leetcode.com/problems/ant-on-the-boundary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        long long pos = 0;
        int cnt = 0;
        for (int x : nums) {
            pos += x;
            if (pos == 0) cnt++;
        }
        return cnt;
    }
};
