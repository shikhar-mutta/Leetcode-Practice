// Link: https://leetcode.com/problems/duplicate-zeros/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        vector<int> res;
        for (int x : arr) {
            if ((int)res.size() >= n) break;
            res.push_back(x);
            if (x == 0 && (int)res.size() < n) res.push_back(0);
        }
        arr = res;
    }
};
