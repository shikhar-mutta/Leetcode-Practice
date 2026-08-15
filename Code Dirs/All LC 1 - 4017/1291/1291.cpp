// Link: https://leetcode.com/problems/sequential-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string digits = "123456789";
        for (int len = 1; len <= 9; len++) {
            for (int start = 0; start + len <= 9; start++) {
                int num = stoi(digits.substr(start, len));
                if (num >= low && num <= high) res.push_back(num);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
