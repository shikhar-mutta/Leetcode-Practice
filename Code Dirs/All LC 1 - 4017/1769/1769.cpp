// Link: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);
        int count = 0;
        long long ops = 0;
        for (int i = 0; i < n; i++) {
            res[i] += ops;
            if (boxes[i] == '1') count++;
            ops += count;
        }
        count = 0; ops = 0;
        for (int i = n - 1; i >= 0; i--) {
            res[i] += ops;
            if (boxes[i] == '1') count++;
            ops += count;
        }
        return res;
    }
};
