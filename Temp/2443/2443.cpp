// Link: https://leetcode.com/problems/sum-of-number-and-its-reverse/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int a = 0; a <= num; a++) {
            string s = to_string(a);
            reverse(s.begin(), s.end());
            int b = stoi(s);
            if (a + b == num) return true;
        }
        return false;
    }
};
