// Link: https://leetcode.com/problems/build-an-array-with-stack-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int idx = 0;
        for (int num = 1; num <= n && idx < (int)target.size(); num++) {
            res.push_back("Push");
            if (target[idx] == num) {
                idx++;
            } else {
                res.push_back("Pop");
            }
        }
        return res;
    }
};
