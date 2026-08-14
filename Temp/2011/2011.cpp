// Link: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for (auto& op : operations) {
            if (op[1] == '+') x++;
            else x--;
        }
        return x;
    }
};
